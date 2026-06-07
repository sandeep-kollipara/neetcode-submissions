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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        auto postorder_dfs=[&](auto&& self, TreeNode* node){
            // termination
            if (node==nullptr) return make_pair(true,9999);
            // traversal
            bool status = false;
            pair<bool,int> left_pair = self(self, node->left);
            pair<bool,int> right_pair = self(self, node->right);
            // check for leaf nodes
            if (left_pair.second==right_pair.second and left_pair.second==9999) {
                count++;
                return make_pair(true,node->val);
            }
            // check for one child nodes
            else if ((left_pair.second==9999 and right_pair.second==node->val and right_pair.first) 
            or (right_pair.second==9999 and left_pair.second==node->val and left_pair.first)) {
                count++;
                status = true;
            }
            // check for two child nodes
            else if (left_pair.first and right_pair.first and left_pair.second==right_pair.second and left_pair.second==node->val) {
                count++;
                status = true;
            }
            return make_pair(status,node->val);
        };
        postorder_dfs(postorder_dfs, root);
        return count;
    }
};
