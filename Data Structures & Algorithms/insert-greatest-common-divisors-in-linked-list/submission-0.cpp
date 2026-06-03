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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        function<int(int,int)> gcd=[](int a, int b) { // can be optimized
            int res=1;
            for (int i=1; i<=min(a,b); i++) {
                if (a%i==0 and b%i==0) res=i;
            }
            return res;
        };
        ListNode* node = head;
        while(node->next!=nullptr) {
            int a = node->val;
            int b = node->next->val;
            ListNode* neuva = new ListNode(gcd(a, b), node->next);
            ListNode* temp = node->next;
            node->next = neuva;
            node = temp;
        }
        return head;
    }
};