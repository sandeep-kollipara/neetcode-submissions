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
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* curr=head, *next, *plus=nullptr, *minus=nullptr, *positive=nullptr, *negative=nullptr, *last_posi=nullptr, *last_nega=nullptr;
        while (curr) {
            next=curr->next;
            curr->next=nullptr;
            if (curr->val >= 0) {
                if (not positive) plus = curr;
                last_posi = positive;
                positive = curr;
                if (last_posi) last_posi->next = positive;
            } else if (curr->val < 0) {
                if (not negative) minus = curr;
                last_nega = negative;
                negative = curr;
                negative->next = last_nega;
            }
            curr=next;
        }
        if (minus) {
            minus->next = plus;
            return negative;
        }
        else return plus;
    }
};
