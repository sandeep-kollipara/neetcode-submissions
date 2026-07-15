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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        auto merge_tree=[](auto&& self, TreeNode* node1, TreeNode* node2){
            // base case or termination
            if (node1==nullptr and node2==nullptr) return (TreeNode*)nullptr;
            // traversal
            TreeNode* neuva;
            if (node1==nullptr){
                neuva = node2;
                //neuva->left = self(self, nullptr, node2->left);
                //neuva->right = self(self, nullptr, node2->right);
            } else if (node2==nullptr){
                neuva = node1;
                //neuva->left = self(self, node1->left, nullptr);
                //neuva->right = self(self, node1->right, nullptr);
            } else {
                neuva = node1;
                neuva->val = node1->val + node2->val;
                neuva->left = self(self, node1->left, node2->left);
                neuva->right = self(self, node1->right, node2->right);
            }
            return neuva;
        };
        return merge_tree(merge_tree, root1, root2);
    }
};