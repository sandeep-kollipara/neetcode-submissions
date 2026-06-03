/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> s;
        ListNode* curr = head;
        int m=0;
        while(curr!=nullptr){
            s.push(curr);
            curr = curr->next;//update
            m++;
        }
        cout << m << endl;
        ListNode* n_minus_1;
        ListNode* n_plus_1;
        for (int i=0; i<min(m+1,n+1); i++){ // stack limit maintained
            // nth element may be first element
            if (n <= 1) n_minus_1 = nullptr; // edge case of n == 1
            else if (i==n-2 and n > 1) n_minus_1 = s.top();
            /*else */if (i==n and n==m) n_plus_1 = nullptr; // edge case of n == m (exception before general case)
            else if (i==n) n_plus_1 = s.top();
            s.pop();
        }
        if (n==1 and m <= n) head = nullptr; // edge #1 and #2
        else if (n==1) n_plus_1->next = nullptr; // edge #1
        else if (m <= n) head = n_minus_1; // edge #2
        else n_plus_1->next = n_minus_1; // general
        return head;
    }
};
