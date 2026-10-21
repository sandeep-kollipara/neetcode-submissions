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
    int equalToDescendants(TreeNode* root) {
        int count=0;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (node==nullptr) return 0;
            // post order traversal
            int left = self(self, node->left);
            int right = self(self, node->right);
            if (left+right==node->val) count++;
            return left + right + node->val;
        };
        dfs(dfs, root);
        return count;
    }
};
