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
    ListNode* rotateRight(ListNode* head, int k) {
        if (not head) return head;
        // connect the ends and calculate length
        int i=0;
        ListNode* curr=head, *prev=nullptr;
        while (curr) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        if (prev) prev->next=head;
        int length=i;
        // rotate left by length - k%length
        i=0;
        curr=head;
        prev=nullptr;
        while(i<length-k%length) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        prev->next=nullptr;
        return curr;
    }
};