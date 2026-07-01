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
    Node* findRoot(vector<Node*> tree) {
        // traverse the array and save the top node and its depth, overwrite if it's higher than previous highest
        Node* highest = nullptr;
        int depth=-1, max_depth=-1;
        int i=0;
        Node* deep_node=nullptr;
        auto dfs=[&](auto&& self, Node* node, int depth) -> int {
            // termination
            if (node==nullptr) return depth;
            // traversal
            int curr_depth=depth;
            for (auto child: node->children) {
                if (child==deep_node) {
                    curr_depth = max(depth + max_depth, curr_depth);
                    continue;
                }
                curr_depth = max(self(self, child, depth+1), curr_depth);
            }
            return curr_depth;
        };
        while(i<tree.size()){
            // traverses the array
            depth = dfs(dfs, tree[i], 1);
            if (depth > max_depth) {
                max_depth = depth;
                deep_node = tree[i];
            }
            i++;
        }
        cout << max_depth;
        return deep_node;
    }
};
