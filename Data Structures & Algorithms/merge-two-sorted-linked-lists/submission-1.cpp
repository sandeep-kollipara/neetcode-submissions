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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* neuva;
        ListNode* temp;
        ListNode* merge = (ListNode*)nullptr;
        while (list1!=nullptr or list2!=nullptr) {
            if (list1!=nullptr and (list2 == nullptr or list1->val <= list2->val)) {
                temp = list1;
                list1 = list1->next;
            } else if (list2!=nullptr and (list1 == nullptr or list2->val < list1->val)) {
                temp = list2;
                list2 = list2->next;
            }
            if (merge==nullptr) {
                merge = neuva = temp;
            } else {
                neuva->next = temp;
                neuva = temp;
            }
        }
        return merge;
    }
};
