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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i=0;
        ListNode* node=list1, *prev=nullptr, *before_a, *after_b, *head=list1;
        while (node) {
            if (i==a) before_a=prev;
            if (i==b) after_b=node->next;
            prev=node;
            node=node->next;
            i++;
        }
        //cout << "before a:" << before_a->val << endl;
        //cout << "after b:" << after_b->val << endl;
        node=list2;
        prev=nullptr;
        while(node) {
            prev=node;
            node=node->next;
        }
        //cout << "list2_last:" << prev->val << endl;
        if (before_a) before_a->next = list2;
        else head=list2;
        prev->next = after_b;
        return head;
    }
};
