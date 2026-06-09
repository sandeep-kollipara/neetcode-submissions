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
    bool hasPathSum(TreeNode* root, int targetSum) {
        auto add_dfs=[&](auto&& self, TreeNode* node, int sum) {
            // termination
            if (node==nullptr) return false;
            // traversal
            sum -= node->val;
            if (node->left==nullptr and node->right==nullptr and sum==0) {
                return true;
            }
            return self(self, node->left, sum) 
            or self(self, node->right, sum);
        };
        if (root==nullptr) return false;
        return add_dfs(add_dfs, root, targetSum);
    }
};