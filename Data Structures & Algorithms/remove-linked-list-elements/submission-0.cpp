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
    ListNode* removeElements(ListNode* head, int val) {
        // edge case - head is val
        while (head and head->val==val) head = head->next;
        // other case - mid or tail is val
        ListNode* node = head, *prev = head;
        while (node!=nullptr) {
            if (node->val==val) prev->next = node->next;
            else prev = node;
            node = node->next;
        }
        return head;
    }
};