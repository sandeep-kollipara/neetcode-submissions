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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> lonely;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case
            if (node==nullptr) return -1;
            // post-order traversal
            int left = self(self, node->left);
            int right = self(self, node->right);
            if (left*right<0) {
                if (left<0) lonely.push_back(right);
                else lonely.push_back(left);
            }
            return node->val;
        };
        dfs(dfs, root);
        return lonely;
    }
};
