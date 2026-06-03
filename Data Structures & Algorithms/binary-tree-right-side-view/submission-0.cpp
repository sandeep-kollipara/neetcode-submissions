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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_side;
        int max_depth = -1;
        function<void(TreeNode*, int)> dfs_right_side=[&](TreeNode* node, int depth) {
            if (node==nullptr) return ;
            if (depth > max_depth) {
                right_side.push_back(node->val);
                max_depth = depth;
            }
            dfs_right_side(node->right, depth+1);
            dfs_right_side(node->left, depth+1);
        };
        dfs_right_side(root, 0);
        return right_side;
    }
};
