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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> address_hash_map = {};
        ListNode* curr = head;
        int index=0;
        while(address_hash_map.find(curr)==address_hash_map.end()){
            if (curr == nullptr) return false;
            address_hash_map[curr] = index;
            //if (curr->next == nullptr) return false;
            curr = curr->next; //update
            index++;
        }
        return true;
    }
};
