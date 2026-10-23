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
    ListNode* swapPairs(ListNode* head) {
        if (not head) return head;
        // 3 connections to be changes between 4 nodes
        ListNode* prev=nullptr, *first=head, *second=head->next, *next=nullptr;
        if (head and head->next) next = head->next->next;
        if (second) head = second;
        while (first and second) {
            // reattach prev to second
            if (prev) prev->next = second;
            // attach first to second
            second->next = first;
            // attach next to first
            first->next = next;
            // move two spots ahead
            prev = first;
            first = next;
            second = ((next) ? next->next : nullptr);
            next = ((next and next->next) ? next->next->next : nullptr);
        }
        return head;
    }
};
