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
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter=0 /*center*/;
        function<int(TreeNode*)> depth_first_search=[&](TreeNode* node){
            int left_depth=0, right_depth=0;
            // termination at leaves
            if (node==nullptr) return -1;
            // otherwise recurse down and calculate depth
            left_depth = depth_first_search(node->left)+1;
            right_depth = depth_first_search(node->right)+1;
            // update global max_diameter variable
            max_diameter = max(max_diameter, left_depth + right_depth);
            // calculate depth from node and return
            return max(left_depth, right_depth);
        };
        depth_first_search(root);
        return max_diameter;
    }
};
