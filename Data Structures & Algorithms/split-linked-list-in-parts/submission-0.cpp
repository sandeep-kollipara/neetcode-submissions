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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // count the length so as to split it
        ListNode* node = head;
        int i=0, length, extra;
        while (node) {
            node = node->next;
            i++;
        }
        length = i;
        //cout << length << endl;
        // split the length into individual size + extra
        extra = length%k;
        length = length/k;
        //cout << extra << endl;
        //cout << k << endl;
        vector<int> splits;
        for (int i=0; i<k; i++) splits.push_back(length+(k-1+(extra--))/k);
        //for (int i: splits) cout << i << " ";
        vector<ListNode*> res;
        node = head;
        i=0;
        int j=0;
        ListNode* prev=nullptr;
        while (node) {
            prev = node;
            node = node->next;
            i++;
            if (--splits[j]==0) {
                prev->next = nullptr;
                res.push_back(head);
                head=node;
                j++;
            }
        }
        while (res.size()<splits.size()) res.push_back(nullptr);
        return res;
    }
};
