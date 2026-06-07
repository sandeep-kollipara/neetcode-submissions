/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> onion;
        auto postorder_dfs=[&](auto&& self, TreeNode* node) {
            // termination
            if (node==nullptr) return -1;
            // traversal
            int left_depth = self(self, node->left);
            int right_depth = self(self, node->right);
            int depth = max(left_depth, right_depth)+1;
            if (depth >= 0) {
                if (onion.size()>depth) onion[depth].push_back(node->val);
                else onion.push_back(vector<int>(1, node->val));
            }
            return depth;
        };
        postorder_dfs(postorder_dfs, root);
        return onion;
    }
};
