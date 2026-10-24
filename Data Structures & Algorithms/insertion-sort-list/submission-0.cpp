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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted = new ListNode(INT_MIN), *node, *node2, *prev;
        while (head) {
            node = head;
            head = head->next;
            prev = nullptr;
            node2 = sorted;
            while (node2 and node->val > node2->val) {
                prev = node2;
                node2 = node2->next;
            }
            prev->next = node;
            node->next = node2;
        }
        return sorted->next;
    }
};