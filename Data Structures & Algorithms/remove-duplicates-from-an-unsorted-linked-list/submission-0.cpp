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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int,int> hashmap;
        ListNode* node=head;
        while (node) {
            hashmap[node->val]++;
            node=node->next;
        }
        ListNode* dummyhead = new ListNode(-1), *prev, *next;
        dummyhead->next = head;
        node=dummyhead;
        prev=nullptr;
        while (node) {
            next = node->next;
            if (hashmap[node->val]>1) {
                delete node;
                prev->next = next;
                node = prev;
                continue;
            }
            prev = node;
            node = next;
        }
        return dummyhead->next;
    }
};
