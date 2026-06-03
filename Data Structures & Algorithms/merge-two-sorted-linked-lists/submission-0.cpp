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
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        while(curr1!=nullptr or curr2!=nullptr){
            // next is either list1's curr or list2's curr
            if (curr1!= nullptr and curr2!=nullptr){
                if (curr1->val < curr2->val) {
                    if (head==nullptr) {
                        head = curr1;
                        tail = curr1;
                        curr1 = curr1->next;
                    }
                    else {
                        tail->next = curr1;
                        curr1 = curr1->next;
                        tail = tail->next;
                    }
                }
                else{
                    if (head==nullptr) {
                        head = curr2;
                        tail = curr2;
                        curr2 = curr2->next;
                    }
                    else {
                        tail->next = curr2;
                        curr2 = curr2->next;
                        tail = tail->next;
                    }
                }
            }
            else{
                if (curr1==nullptr) {
                    if (head==nullptr) head = curr2;
                    else tail->next = curr2;
                    curr2 = nullptr; // termination
                }
                else {
                    if (head==nullptr) head = curr1;
                    else tail->next = curr1;
                    curr1 = nullptr; // termination
                }
            }
        }
        return head;
    }
};
