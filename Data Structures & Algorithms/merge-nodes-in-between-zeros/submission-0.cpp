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
    ListNode* mergeNodes(ListNode* head) {
        int cart=0;
        ListNode* node = head, *head2=nullptr, *node2;
        while (node) {
            if (node->val==0 and cart) {
                node->val=cart;
                cart=0;
                if (not head2) {
                    head2 = node;
                    node2 = head2;
                } else {
                    node2->next = node;
                    node2 = node;
                }
            } else {
                cart+=node->val;
                node->val=0;
            }
            node = node->next;
        }
        //node2->next = nullptr;
        return head2;
    }
};
