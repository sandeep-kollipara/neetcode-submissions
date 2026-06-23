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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto recurse=[&](auto&& self, ListNode* head) -> ListNode* {
            // check if k nodes are present from the current node
            ListNode *curr = head, *first = head, *inter, *k_plus_1, *tail = head;
            int num=0;
            while(curr!=nullptr and num<k) {
                num++;
                curr = curr->next;
            }
            //cout << "num: " << num << endl;
            //if (curr!=nullptr) cout << "curr->val:" << curr->val << endl;
            k_plus_1 = curr;
            //cout << k_plus_1 << endl;
            // if yes, save the k+1 node address and add 1st node to kth node to it in a reverse fashion
            if (num==k){
                int i=0;
                while(i<k){
                    //cout << first->val << " " << endl; 
                    inter = first->next;
                    first->next = curr;
                    curr = first;
                    first = inter;
                    i++;
                }
                if (k_plus_1!=nullptr) tail->next=self(self, k_plus_1);
            } else return head; /*if (k_plus_1!=nullptr) cout << k_plus_1->val << endl;*/ // else no, do nothing a.k.a termination of recursion 
            return curr;
        };
        return recurse(recurse, head);
    }
};
