/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> hashset1({p}), hashset2({q});
        while (not (hashset1.count(q) or hashset2.count(p))) {
            if (p) p = p->parent;
            if (q) q = q->parent;
            if (p) hashset1.insert(p);
            if (q) hashset2.insert(q);
            if (not p and not q) break;
        }
        if (q and hashset1.count(q)) return q;
        else if (p and hashset2.count(p)) return p;
        else return nullptr;
    }
};