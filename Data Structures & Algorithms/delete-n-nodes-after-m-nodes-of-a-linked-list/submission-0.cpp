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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* node=head, *prev = nullptr;
        int i=1;
        while (node) {
            if (i==m) prev = node;
            if (i==m+n) {
                prev->next = node->next;
                i=0;
            }
            node = node->next;
            i++;
        }
        if (i>m) prev->next=nullptr;
        return head;
    }
};
