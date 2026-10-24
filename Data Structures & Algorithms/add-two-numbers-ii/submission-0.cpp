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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto reverse=[](ListNode* node){
            ListNode* prev=nullptr, *next;
            while (node) {
                next = node->next;
                node->next = prev;
                // upkeep
                prev = node;
                node = next;
            }
            return prev;
        };
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* num1=l1, *num2=l2, *prev=nullptr, *prev2=nullptr;
        int carry=0, sum=0;
        while (num1 or num2) {
            if (num1 and num2) sum = num1->val + num2->val + carry;
            else if (num1) {
                sum = num1->val + carry;
                num2 = prev2->next = new ListNode(0);
            } else {
                sum = num2->val + carry;
                num1 = prev->next = new ListNode(0);
            }
            carry = sum/10;
            num1->val = sum%10;
            prev = num1;
            prev2 = num2;
            num1 = num1->next;
            num2 = num2->next;
        }
        if (not num1 and not num2) {
            if (carry) prev->next = new ListNode(carry);
        }
        return reverse(l1);
    }
};