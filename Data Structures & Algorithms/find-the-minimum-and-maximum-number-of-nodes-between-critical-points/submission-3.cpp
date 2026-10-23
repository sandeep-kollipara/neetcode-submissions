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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev2=nullptr, *prev=nullptr, *curr=head;
        int i=0, first=-1, last=-1, maximum=INT_MIN, minimum=INT_MAX;
        while (curr) {
            if (prev2 and prev 
            and ((prev->val > curr->val 
            and prev2->val < prev->val) 
            or (prev->val < curr->val 
            and prev2->val > prev->val))) {
                if (first==-1) first=last=i;
                else {
                    minimum = min(minimum, i-last);
                    last=i;
                }
            }
            prev2 = prev;
            prev = curr;
            curr = curr->next;
            i++;
        }
        if (first == -1 or first==last) return {-1,-1};
        maximum=last-first;
        return {minimum, maximum};
    }
};
