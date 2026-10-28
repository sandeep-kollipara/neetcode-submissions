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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* root2=nullptr;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node) return ;
            // post-order traversal
            self(self, node->left);
            self(self, node->right);
            if (not root2) root2=node;
            if (node->left) { // only for the left
                node->left->left = node->right;
                node->left->right = node;
            }
            node->left = node->right = nullptr;
            return ;
        };
        dfs(dfs, root);
        return root2;
    }
};
