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
    int sumNumbers(TreeNode* root) {
        int sum=0;
        auto dfs=[&](auto&& self, TreeNode* node, int val){
            // base case or termination
            if (not node) return ;
            // pre-order traversal
            val*=10;
            val+=node->val;
            if (not node->left and not node->right) { // leaf
                sum+=val;
            }
            self(self, node->left, val);
            self(self, node->right, val);
            return ;
        };
        dfs(dfs, root, 0);
        return sum;
    }
};