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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Copied the below lambda from 'Same Binary Tree' problem
        function<bool(TreeNode*, TreeNode*)> compare_two_trees=[&](TreeNode* a, TreeNode* b){
            if (a==nullptr and b == nullptr) return true;
            else if (a==nullptr or b == nullptr) return false;
            if (a->val != b->val) return false;
            bool left_branch = compare_two_trees(a->left, b->left);
            bool right_branch = compare_two_trees(a->right, b->right);
            return (left_branch and right_branch);
        };
        int target = subRoot->val;
        function<bool(TreeNode*)> recursive_tree_traversal=[&](TreeNode* node){
            bool comparison = false, left_branch = false, right_branch = false;
            // Leaf node - > compare if both empty (edge case)
            if (node==nullptr) comparison = (node==subRoot);
            // Same node value as subroot -> compare trees (general)
            else if (node->val==target) {
                comparison = compare_two_trees(node, subRoot);
            }
            // Check its children (recursion)
            if (node!=nullptr) {
                left_branch = recursive_tree_traversal(node->left);
                right_branch = recursive_tree_traversal(node->right);
            }
            return (left_branch or right_branch or comparison);
        };
        return recursive_tree_traversal(root);
    }
};
