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
        ListNode* node=head;
        int len=0;
        while (node!=nullptr) {
            node = node->next;
            len++;
        }
        node = head;
        stack<int> stk;
        for (int i=0; i<len/2; i++) {
            stk.push(node->val);
            node = node->next;
        }
        if (len%2) node = node->next;
        while (node!=nullptr) {
            if (stk.top()==node->val) stk.pop();
            else return false; 
            node = node->next;
        }
        return true;
    }
};