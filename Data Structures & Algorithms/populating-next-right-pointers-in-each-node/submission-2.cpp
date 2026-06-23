/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root==nullptr) return root;
        // reverse post order - center right left
        auto rpo=[](auto&& self, Node* node, Node* prev) {
            // termination
            if (node==nullptr) return (Node*)nullptr;
            // traversal
            node->next = prev;
            if (prev!=nullptr) prev = prev->left;
            prev = self(self, node->right, prev);
            prev = self(self, node->left, prev);
            return node;
        };
        return rpo(rpo, root, nullptr);
    }
};