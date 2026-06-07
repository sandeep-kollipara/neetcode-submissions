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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        auto search_bst=[&](int value){
            TreeNode* node = root2;
            while(node!=nullptr) {
                if (value > node->val) {
                    node = node->right;
                } else if (value < node->val) {
                    node = node->left;
                } else return true;
            }
            return false;
        };
        auto inorder_dfs=[&](auto&& self, TreeNode* node) {
            // termination
            if (node==nullptr) return false;
            // traversal
            bool left = self(self, node->left);
            bool center = search_bst(target-node->val);
            bool right = self(self, node->right);
            return left or center or right;
        };
        return inorder_dfs(inorder_dfs, root1);
    }
};
