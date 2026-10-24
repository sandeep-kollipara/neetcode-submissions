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
    ListNode* partition(ListNode* head, int x) {
        // Tail approach
        ListNode* sentinel = new ListNode(INT_MAX);
        sentinel->next = head;
        ListNode* tail = new ListNode(INT_MIN);
        ListNode *tail2=tail, *node = sentinel, *prev=nullptr, *next;
        while (node) {
            next = node->next;
            if (node->val < x) {
                tail2->next = node;
                tail2 = node;
                prev->next = next;
                node = next;
                continue;
            }
            prev = node;
            node = next;
        }
        tail2->next = sentinel->next;
        return tail->next;
    }
};
