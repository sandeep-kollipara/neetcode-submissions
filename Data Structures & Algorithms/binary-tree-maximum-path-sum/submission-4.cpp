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
    int maxPathSum(TreeNode* root) {
        int path_sum=root->val;//INT_MIN;
        auto post_order_dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (node==nullptr) return 0;
            // traversal
            int left_sum_max, right_sum_max;
            left_sum_max = self(self, node->left);
            right_sum_max = self(self, node->right);
            path_sum = max(node->val, max(path_sum, max(left_sum_max+right_sum_max+node->val, max(left_sum_max+node->val, right_sum_max+node->val))));
            return max(node->val, max(node->val+left_sum_max, node->val+right_sum_max));
        };
        post_order_dfs(post_order_dfs, root);
        return path_sum;
    }
};
