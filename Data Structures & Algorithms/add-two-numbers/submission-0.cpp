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
        int carry=0, sum;
        ListNode* x = l1;
        ListNode* y = l2;
        ListNode* add = nullptr;
        ListNode* prev = nullptr;
        while(x!=nullptr or y!=nullptr) {
            if (x==nullptr) sum = y->val + carry;
            else if (y==nullptr) sum = x->val + carry;
            else sum = x->val + y->val + carry;
            cout << sum % 10 << endl;
            ListNode* neuva = new ListNode(sum % 10);
            if (add==nullptr) add = neuva;
            if (prev!=nullptr) prev->next = neuva;
            prev = neuva;
            carry = sum / 10;
            if (x!=nullptr) x = x->next;
            if (y!=nullptr) y = y->next;
        }
        if (carry>0) {
            ListNode* neuva = new ListNode(carry);
            prev->next = neuva;
        }
        return add;
    }
};
