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
    ListNode* removeNodes(ListNode* head) {
        // make a pass and add index and value to monotonic stack
        ListNode* node=head, *temp;
        stack<ListNode*> stk;
        int i=0;
        while (node) {
            while(stk.size() and stk.top()->val<node->val){
                delete stk.top();
                stk.pop();
            }
            stk.push(node);
            node = node->next;
            i++;
        }
        while (stk.size()) {
            stk.top()->next = node;
            node = stk.top();
            stk.pop();
        }
        return node;
    }
};
