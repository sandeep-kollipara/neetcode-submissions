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
        vector<int> critical;
        int i=0;
        while (curr) {
            if (prev2 and prev 
            and ((prev->val > curr->val 
            and prev2->val < prev->val) 
            or (prev->val < curr->val 
            and prev2->val > prev->val))) critical.push_back(i);
            prev2 = prev;
            prev = curr;
            curr = curr->next;
            i++;
        }
        if (critical.size()<2) return {-1,-1};
        int maximum=INT_MIN, minimum=INT_MAX;
        for (int i=1; i<critical.size(); i++) {
            minimum=min(minimum, critical[i]-critical[i-1]);
        }
        maximum=critical[critical.size()-1]-critical[0];
        return {minimum, maximum};
    }
};
