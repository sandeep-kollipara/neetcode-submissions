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
    TreeNode* reverseOddLevels(TreeNode* root) {
        auto bidfs=[](auto&& self, TreeNode* left, TreeNode* right, int depth){
            // base case or termination
            if (not left or not right) return ;
            // traversal
            self(self, left->left, right->right, depth+1);
            self(self, left->right, right->left, depth+1);
            if (depth%2) swap(left->val, right->val);
        };
        bidfs(bidfs, root->left, root->right, 1);
        return root;
    }
};
