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
    int pairSum(ListNode* head) {
        auto reverse=[](ListNode* node){
            ListNode* prev=nullptr, *next;
            while (node) {
                next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }
            return prev;
        };
        // slow and fast pointers - halfway point
        ListNode *node=head;
        int i=0, length;
        while (node) {
            node = node->next;
            i++;
        }
        length = i;
        node = head;
        ListNode *fast=head, *slow=head, *last;
        i=0;
        while (fast) {
            fast = fast->next->next;
            if (not fast) last = slow;
            slow = slow->next;
            i++;
        }
        last->next = nullptr;
        // reverse the other half, traverse both and add
        slow = reverse(slow);
        int twin_sum=INT_MIN;
        while (head and slow) {
            twin_sum = max(twin_sum, head->val+slow->val);
            head = head->next;
            slow = slow->next;
        }
        return twin_sum;
    }
};