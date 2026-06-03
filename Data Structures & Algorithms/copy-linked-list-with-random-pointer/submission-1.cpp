/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // edge case
        if (head==nullptr) return nullptr;
        Node* copy = nullptr;
        // first pass - 1) create a copy of the linked list without random pointer
        // 2) save the addresses of all new nodes in an array
        // 3) create a hash-map of index to random pointer index for original
        vector<Node*> addr;
        unordered_map<Node*, int> hash_map;
        Node* iter = head;
        Node* prev = nullptr;
        int i=0;
        while (iter!=nullptr) {
            // original
            int val = iter->val;
            // new copy
            Node* neuva = new Node(val);
            if (prev!=nullptr) prev->next = neuva;
            prev = neuva;
            // save address
            addr.push_back(neuva);
            // create hash-map
            hash_map[iter]=i;
            iter = iter->next;
            i++;
        }
        // second pass - update the new linked list's random pointer using the hash-map and array
        Node* iter2 = addr[0];
        iter = head;
        while(iter!=nullptr or iter2!=nullptr) {
            if (iter->random==nullptr) iter2->random=nullptr;
            else iter2->random = addr[hash_map[iter->random]];
            iter = iter->next;
            iter2 = iter2->next;
        }
        return addr[0];
    }
};
