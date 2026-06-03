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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        function<ListNode*(ListNode*,int,int)> switchLeftAndRight=[](ListNode* head, int left, int right) {
            // 2 cases: if head is left or not
            // 2 cases: if tails is right or not
            // +1 case: left is right
            if (left==right) return head; // edge case
            // prev1 -> left -> next1 -> prev2 -> right -> next2
            // find left: save prev1, next1
            // find right: save prev2 next2
            int i=0;
            ListNode* node = head;
            ListNode* prev1=nullptr;
            ListNode* lefty=nullptr;
            ListNode* next1=nullptr;
            ListNode* prev2=nullptr;
            ListNode* righty=nullptr;
            ListNode* next2=nullptr;
            while (node!=nullptr) { // traversal to find all
                i++;
                if (i==left-1) {
                    prev1 = node;
                } else if (i==left) {
                    lefty = node;
                } else if (i==left+1) {
                    next1 = node;
                }
                if (i==right-1) {
                    prev2 = node;
                } else if (i==right) {
                    righty = node;
                } else if (i==right+1) {
                    next2 = node;
                }
                node = node->next;
            }
            // connect right to prev1
            // connect next1 to right
            // connect left to prev2
            // connect next2 to left
            if (prev1!=nullptr) prev1->next = righty; // left is not head (originally)
            else head = righty; // left is head (originally)
            if (next1!=righty) righty->next = next1; // left is not adjacent to right
            else righty->next = lefty; // left is adjacent to right
            if (prev2!=lefty) prev2->next = lefty; // left is not adjacent to right
            else ; // left is adjacent to right
            lefty->next = next2;
            return head;
        };
        ListNode* neuva = head;
        while (left<=right) {
            neuva = switchLeftAndRight(neuva, left, right);
            left++;
            right--;
        }
        return neuva;
    }
};