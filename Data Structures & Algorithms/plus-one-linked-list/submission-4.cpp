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
    ListNode* plusOne(ListNode* head) {
        int i=0, last_nonnine=-1;
        ListNode* node=head;
        while (node) {
            if (node->val!=9) {
                last_nonnine=i;
            }
            node = node->next;
            i++;
        }
        if (last_nonnine==-1) {
            node=head;
            while (node) {
                node->val=0;
                node=node->next;
            }
            ListNode* nouveau = new ListNode(1);
            nouveau->next = head;
            head = nouveau;
        } else {
            node=head;
            i=0;
            while (node) {
                if (i>last_nonnine) node->val=0;
                else if (i==last_nonnine) node->val++;
                node=node->next;
                i++;
            }
        }
        return head;
    }
};
