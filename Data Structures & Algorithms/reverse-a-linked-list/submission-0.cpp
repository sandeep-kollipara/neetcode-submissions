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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr!=nullptr){
            // keep the ptr to next node
            ListNode* next = curr->next;
            // detach the current node and connect with previous
            curr->next = prev;
            cout << curr->val << " ";
            // make next node current and current node previous
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
