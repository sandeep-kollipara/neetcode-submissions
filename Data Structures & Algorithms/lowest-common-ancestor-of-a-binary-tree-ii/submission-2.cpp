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
        TreeNode* res=nullptr;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case
            if (node==nullptr) return pair<bool,bool>({false,false});
            // post order traversal
            pair<bool,bool> left = self(self, node->left);
            pair<bool,bool> right = self(self, node->right);
            if (node==p) left.first=true;
            else if (node==q) left.second=true;
            pair<bool,bool> out = {left.first or right.first, left.second or right.second};
            if (not res and out.first and out.second) res=node;
            return out;
        };
        dfs(dfs, root);
        return res;
    }
};
