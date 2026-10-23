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
        // reverse the linked list
        auto reverse=[](ListNode* first){
            ListNode* node = first, *next=node->next, *after;
            node->next = nullptr;
            while (node and next) {
                after = next->next;
                next->next = node;
                node = next;
                next = after;
            }
            return node;
        };
        head = reverse(head);
        ListNode* node=head, *prev;
        int carry=1;
        while (node) {
            if (node->val%10) {
                node->val+=carry;
                carry=(node->val/10);
                node->val%=10;
                prev = node;
                node = node->next;
            } else {
                node->val+=carry;
                carry=0;
                break;
            }
        }
        if (carry) {
            ListNode* nouveau = new ListNode(carry);
            prev->next = nouveau;
        }
        return reverse(head);
    }
};
