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
        // calculate height to root
        int i=0;
        Node* t=p;
        while (t) {
            t = t->parent;
            i++;
        }
        int height1=i;
        i=0;
        t = q;
        while (t) {
            t = t->parent;
            i++;
        }
        int height2=i;
        while (height1 > height2) {
            p = p->parent;
            height1--;
        }
        while (height1 < height2) {
            q = q->parent;
            height2--;
        }
        while (p!=q) {
            p=p->parent;
            q=q->parent;
        }
        return p;
    }
};