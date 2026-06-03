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
    void reorderList(ListNode* head) {
        //vector<ListNode*> address_list = {};
        queue<int> q = {};
        stack<int> s = {};
        ListNode* curr = head;
        int val, n = 0;
        while(curr!=nullptr){
            //address_list[n] = curr;
            val = curr->val;
            q.push(val);
            s.push(val);
            curr = curr->next; //update
            n++;
        }
        // Population time by rewriting the original LL
        /*ListNode* */curr = head;
        for (int i = 0; i < n; i++){
            if (i%2 == 0) {
                val = q.front();
                q.pop();
                //address_list[i]->val = val;
            }
            else{
                val = s.top();
                s.pop();
                //address_list[i]->val = val;
            }
            curr->val = val;
            curr = curr->next;
        }
    }
};
