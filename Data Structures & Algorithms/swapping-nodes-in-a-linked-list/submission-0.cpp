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
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;
        // first pass - find and store first node (k), calc length
        ListNode* node = sentinel, *prev=nullptr, *kth, *kprev;
        int i=-1;
        while (node) {
            prev = node;
            node = node->next;
            i++;
            if (i==k-1) {
                kth = node;
                kprev = prev;
            }
        }
        int length = i;
        //cout << kprev->val << " " << kth->val << endl;
        // second pass - find and store second node (len-k)
        ListNode* kminus, *kprev2;
        node = sentinel;
        prev = nullptr;
        i=-1;
        while (node) {
            prev = node;
            node = node->next;
            i++;
            if (i==length-k) {
                kminus = node;
                kprev2 = prev;
                break;
            }
        }
        //cout << kprev2->val << " " << kminus->val << endl;
        // swap
        if (kth==kminus) return head;
        //if (kth==head) kprev=sentinel;
        //if (kminus==head) kprev2=sentinel;
        kprev->next = kminus;
        kprev2->next = kth;
        node = kminus->next;
        kminus->next = kth->next;
        kth->next = node;
        return sentinel->next;
    }
};
