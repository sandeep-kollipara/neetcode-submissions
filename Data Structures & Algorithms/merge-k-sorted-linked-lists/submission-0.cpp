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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        class Compare {
        public:
            bool operator()(pair<int, ListNode*> a, pair<int, ListNode*> b) {
                if(a.first > b.first) {
                    return true;
                }
                return false;
            }
        };
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Compare> pq={};
        for (ListNode* ptr: lists) {
            if (ptr==nullptr) continue;
            pair<int, ListNode*> ins = {ptr->val, ptr};
            pq.push(ins);
        }

        ListNode* head = nullptr;
        if (lists.size()==0) return head;
        ListNode* curr = head;
        while (not pq.empty()){
            // extract min from prioqueue
            pair<int, ListNode*> minimum = pq.top();
            pq.pop();
            // append min to curr and forward if curr is not nullptr else assign min to curr
            if (curr==nullptr) head = curr = minimum.second;
            else {
                curr->next = minimum.second;
                curr = curr->next;
            }
            // push next of curr to prioqueue if next is not nullptr
            if (curr->next!=nullptr){
                pair<int, ListNode*> ins = {curr->next->val, curr->next};
                pq.push(ins);
            }
        }

        return head;
    }
};
