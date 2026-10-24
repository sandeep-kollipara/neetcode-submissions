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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (not head) return head;
        unordered_set<int> hashset;
        while (nums.size()) {
            hashset.insert(nums.back());
            nums.pop_back();
        }
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;
        ListNode* node=sentinel, *prev=nullptr, *next;
        while (node) {
            next = node->next;
            if (hashset.find(node->val)!=hashset.end()) {
                delete node;
                if (prev) prev->next = next;
                node = next;
                continue;
            }
            prev = node;
            node = next;
        }
        return sentinel->next;
    }
};
