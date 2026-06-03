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
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr) return head;
        ListNode* reverse = new ListNode(head->val);
        ListNode* node = head;
        ListNode* neuva;
        while (node->next != nullptr) {
            node = node->next;
            neuva = new ListNode(node->val, reverse);
            reverse = neuva;
        }
        return reverse;
    }
};
