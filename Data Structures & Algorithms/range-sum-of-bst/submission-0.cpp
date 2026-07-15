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
    int rangeSumBST(TreeNode* root, int low, int high) {
        auto preorder_traversal=[&](auto&& self, TreeNode* node, int& sum){
            // base case or termination
            if (node==nullptr) return ;
            // traversal
            if (node->val >= low and node->val <= high) sum+=node->val;
            if (node->val <= high) self(self, node->right, sum);
            if (node->val >= low) self(self, node->left, sum);
        };
        int sum=0;
        preorder_traversal(preorder_traversal, root, sum);
        return sum;
    }
};