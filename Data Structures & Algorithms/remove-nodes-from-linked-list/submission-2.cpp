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
    ListNode* removeNodes(ListNode* head) {
        auto reverse=[](ListNode* node){
            ListNode* curr=node, *next=node->next, *prev=nullptr;
            while (curr) {
                next = curr->next;
                if (prev) curr->next = prev;
                prev = curr;
                curr = next;
            }
            node->next = nullptr;
            return prev;
        };
        head = reverse(head);
        ListNode* node=head, *next, *prev=nullptr;
        int maximum=INT_MIN;
        while (node) {
            next = node->next;
            if (node->val >= maximum) {
                maximum = node->val;
                prev = node;
            } else {
                delete node;
                prev->next = next;
            }
            node=next;
        }
        return reverse(head);
    }
};
