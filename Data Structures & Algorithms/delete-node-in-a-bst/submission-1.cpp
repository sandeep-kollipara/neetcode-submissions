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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = root;
        TreeNode* prev = nullptr;
        while (node!=nullptr) {
            // search
            if (node->val > key and node->left!=nullptr) {
                prev = node;
                node = node->left;
            } else if (node->val < key and node->right!=nullptr) {
                prev = node;
                node = node->right;
            } else if (node->val == key) {
                break;
            } else return root;
        }
        // Case 1: Both children are absent
        if (node->left==nullptr and node->right==nullptr) {
            if (prev==nullptr) return prev; // edge case
            if (prev->left==node) prev->left=nullptr;
            else prev->right=nullptr;
        }
        // Case 2: One of the children is absent
        else if (node->left==nullptr and !(node->right==nullptr)) {
            if (prev==nullptr) return node->right; // edge case
            if (prev->left==node) prev->left=node->right;
            else prev->right=node->right;
        } else if (!(node->left==nullptr) and node->right==nullptr) {
            if (prev==nullptr) return node->left; // edge case
            if (prev->left==node) prev->left=node->left;
            else prev->right=node->left;
        }
        // Case 3: Both children are present
        else {
            if (prev==nullptr) root = node->right; // edge case
            // First attach right node to previous's connection to node
            else {
                if (prev->left==node) prev->left=node->right;
                else prev->right=node->right;
            }
            // Next search the left side of right node to insert left node
            TreeNode* node2 = node->right->left;
            if (node2==nullptr) node->right->left = node->left;
            int left_val = node->left->val;
            while (node2!=nullptr) {
                if (node2->val > left_val and node2->left!=nullptr) node2=node2->left;
                else if (node2->val < left_val and node2->right!=nullptr) node2=node2->right;
                else {
                    if (node2->val > left_val) node2->left = node->left;
                    else node2->right = node->left;
                    break;
                }
            }
        }
        return root;
    }
};