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
        // use 2 sets of fast and slow pointers until both fast converge
        ListNode *node1=headA, *node2=headB;
        int skip1 = 0;
        while (node1) {
            node1 = node1->next;
            skip1++;
        }
        //cout << skip1 << endl;
        int skip2 = 0;
        while (node2) {
            node2 = node2->next;
            skip2++;
        }
        //cout << skip2 << endl;
        node1 = headA;
        node2 = headB;
        if (skip1>skip2) {
            while (skip1!=skip2) {
                node1 = node1->next;
                skip1--;
            }
        } else {
            while (skip1!=skip2) {
                node2 = node2->next;
                skip2--;
            }
        }
        while (node1!=node2) {
            //cout << node1->val << endl;
            //cout << node2->val << endl;
            node1 = node1->next;
            node2 = node2->next;
        }
        return node1;
    }
};