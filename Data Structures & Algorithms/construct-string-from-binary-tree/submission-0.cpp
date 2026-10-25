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
    string tree2str(TreeNode* root) {
        string r;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node) return ;
            // pre-order traversal
            r+=(to_string(node->val));
            if (node->left or node->right) {
                r+='(';
                if (node->left) {
                    self(self, node->left);
                }
                r+=')';
                if (node->right) {
                    r+='(';
                    self(self, node->right);
                    r+=')';
                }
            }
            return ;
        };
        dfs(dfs,root);
        return r;
    }
};
