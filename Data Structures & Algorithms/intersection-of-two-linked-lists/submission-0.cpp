/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> hashset;
        ListNode *node=headA;
        while (node) {
            hashset.insert(node);
            node = node->next;
        }
        node = headB;
        while (node) {
            if (hashset.find(node)!=hashset.end()) {
                return node;
            }
            node = node->next;
        }
        return (ListNode*)nullptr;
    }
};