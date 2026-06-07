/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        auto postorder_dfs=[](auto&& self, Node* node) {
            // termination
            if (node==nullptr) return (Node*)nullptr;
            // traversal
            vector<Node*> copy_children;
            for(Node* child : node->children) copy_children.push_back(self(self, child));
            Node* copy = new Node(node->val, copy_children);
            return copy;
        };
        return postorder_dfs(postorder_dfs, root);
    }
};
