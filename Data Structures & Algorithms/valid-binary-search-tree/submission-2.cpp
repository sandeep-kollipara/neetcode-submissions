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
    bool isValidBST(TreeNode* root) {
        function<bool(TreeNode*, int, int)> recursive_tree_traversal=[&](TreeNode* node, int low, int high) {
            // Base case
            if (node==nullptr) return true;
            // General case
            bool bst_condition = false, center_condition = false, left_condition = false, right_condition = false;
            if (node->val > low and node->val < high) center_condition = true;
            else center_condition = false;
            if (node->left!=nullptr){
                if(node->left->val < node->val) left_condition = true;
                else left_condition = false;
            }
            else left_condition = true;
            if (node->right!=nullptr){
                if(node->right->val > node->val) right_condition = true;
                else right_condition = false;
            }
            else right_condition = true;
            bst_condition = center_condition and left_condition and right_condition;
            if (not bst_condition) return false;
            else return recursive_tree_traversal(node->left, low, node->val) 
            and recursive_tree_traversal(node->right, node->val, high);
        };
        return recursive_tree_traversal(root, -1001, 1001);
    }
};
