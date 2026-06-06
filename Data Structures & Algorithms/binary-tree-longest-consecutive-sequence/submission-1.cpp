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
    int longestConsecutive(TreeNode* root) {
        int maxlen=0;
        auto preorder_dfs=[&](auto&& self, TreeNode* node, int prev, int len) {
            // termination
            if (node==nullptr) return ;
            // traversal
            if (node->val - prev == 1) len++;
            else len=1;
            if (len > maxlen) maxlen = len;
            self(self, node->left, node->val, len);
            self(self, node->right, node->val, len);
        };
        preorder_dfs(preorder_dfs, root, 1e9, 1);
        return maxlen;
    }
};
