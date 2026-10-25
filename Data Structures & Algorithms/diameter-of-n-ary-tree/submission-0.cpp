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
    int diameter(Node* root) {
        int maximum_dia=0;
        auto dfs=[&](auto&& self, Node* node){
            // base case or termination
            if (not node) return -1; 
            // post-order traversal
            int max1=0, max2=0;
            for (auto& child: node->children) {
                int child_depth = self(self, child)+1;
                if (child_depth > max1) {
                    max2 = max1;
                    max1 = child_depth;
                } else if (child_depth > max2) {
                    max2 = child_depth;
                }
            }
            maximum_dia = max(maximum_dia, max1+max2);
            //cout << node->val << " : " << max1+max2 << endl;
            return max(max1,max2);
        };
        dfs(dfs, root);
        return maximum_dia;
    }
};
