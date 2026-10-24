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
        //return reverse(head)->val;
        // find halfway point of linked list
        ListNode *node=head;
        int i=0, length;
        while (node) {
            node = node->next;
            i++;
        }
        length = i;
        node = head;
        ListNode* prev=nullptr, *last, *half;
        i=0;
        while (node) {
            if (i==length/2) break;
            prev = node;
            node = node->next;
            i++;
        }
        prev->next = nullptr;
        last = prev;
        // reverse the other half, traverse both and add
        half = reverse(node);
        node = head;
        int twin_sum=INT_MIN;
        while (head and half) {
            twin_sum = max(twin_sum, head->val+half->val);
            head = head->next;
            half = half->next;
        }
        return twin_sum;
    }
};