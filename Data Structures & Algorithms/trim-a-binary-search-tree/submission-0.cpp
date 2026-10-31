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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node) return (TreeNode*)nullptr;
            //  post-order traversal
            node->left = self(self, node->left);
            node->right = self(self, node->right);
            if (node->val < low) node = node->right;
            else if (node->val > high) node = node->left;
            return node;
        };
        return dfs(dfs, root);
    }
};
