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
    bool isPalindrome(ListNode* head) {
        // fast and slow pointers - reach midpoint and end
        ListNode *fast=head, *slow=head;
        while (fast!=nullptr) {
            fast = fast->next;
            if (fast!=nullptr) fast = fast->next;
            if (fast!=nullptr) slow = slow->next;
        }
        /*while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }*/
        // detach from midpoint and reverse till end then connect back
        ListNode *prev=nullptr, *midpoint=slow, *next;
        cout << midpoint->val;
        slow = slow->next;
        while (slow!=nullptr) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        midpoint->next = prev;
        // check for equality
        ListNode *first=head, *second=midpoint->next;
        while (second!=nullptr) {
            if (first->val!=second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};