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
            if (node->val < low) node = self(self, node->right);
            else if (node->val > high) node = self(self, node->left);
            else {
                node->left = self(self, node->left);
                node->right = self(self, node->right);
            }
            return node;
        };
        return dfs(dfs, root);
    }
};
