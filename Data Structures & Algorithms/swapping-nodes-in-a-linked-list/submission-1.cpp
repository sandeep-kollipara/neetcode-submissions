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
    ListNode* swapNodes(ListNode* head, int k) {
        // first pass - find and store first node (k), calc length
        ListNode* node = head, *kth;
        int i=0;
        while (node) {
            if (i==k-1) {
                kth = node;
            }
            node = node->next;
            i++;
        }
        int length = i;
        //cout << kth->val << endl;
        // second pass - find and store second node (len-k)
        ListNode* kminus;
        node = head;
        i=0;
        while (node) {
            if (i==length-k) {
                kminus = node;
                break;
            }
            node = node->next;
            i++;
        }
        //cout << kminus->val << endl;
        // swap values
        if (kth==kminus) return head;
        i = kth->val;
        kth->val = kminus->val;
        kminus->val = i;
        return head;
    }
};
