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
    int closestValue(TreeNode* root, double target) {
        auto preorder_traversal=[](auto&& self, TreeNode* node, double& closest, double& target){
            // base case or termination
            if (node==nullptr) return ;
            // traversal
            if (abs((double)node->val-target)<abs((double)closest-target)) closest = node->val;
            //if (closest==0) return ;
            if (node->val > target) self(self, node->left, closest, target); // go left
            if (node->val < target) self(self, node->right, closest, target); // go right
            return ;
        };
        double out=INT_MAX;
        preorder_traversal(preorder_traversal, root, out, target);
        return (int)out;
    }
};
