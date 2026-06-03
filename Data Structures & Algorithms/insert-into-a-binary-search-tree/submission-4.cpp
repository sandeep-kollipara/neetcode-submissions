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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* neuva = new TreeNode(val);
        if (root==nullptr) return neuva;
        TreeNode* node = root;
        while(node!=nullptr){
            if (val > node->val and node->right!=nullptr) node = node->right;
            else if (val < node->val and node->left!=nullptr) node = node->left;
            else /*if (val > node->val and node->right==nullptr)*/ {
                if (val > node->val) node->right = neuva;
                else node->left = neuva;
                break;
            }
            /*else if (val < node->val and node->left==nullptr) {
                // attach here
            }*/
        }
        return root;
    }
};