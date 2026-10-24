/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool found=false;
        TreeNode* lca=nullptr;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node or found) return 0;
            // post-order traversal
            int left = self(self, node->left);
            int right = self(self, node->right);
            int center = (node==p or node==q) ? 1 : 0;
            if (not found and left+right+center==2) {
                lca=node;
                found=true;
            }
            return left+right+center;
        };
        dfs(dfs, root);
        return lca;
    }
};