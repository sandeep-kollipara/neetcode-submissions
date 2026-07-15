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
    vector<int> postorder(Node* root) {
        auto post_order_dfs=[](auto&& self, Node* node, vector<int>& arr){
            // base case or termination
            if (node==nullptr) return ;
            // traversal
            for (auto child: node->children) {
                self(self, child, arr);
            }
            arr.push_back(node->val);
        };
        vector<int> out;
        post_order_dfs(post_order_dfs, root, out);
        return out;
    }
};