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
    int maxDepth(TreeNode* root) {
        int final_depth;
        function<int(TreeNode*, int)> recursive_tree_traversal; // comment
        /*function<int(TreeNode*, int)> */recursive_tree_traversal =[&](TreeNode* node, int depth){
            if (node==nullptr) return depth;
            depth++;
            cout << depth << endl;
            int left_depth=depth, right_depth=depth;
            /*if (node->left!=nullptr) */left_depth = recursive_tree_traversal(node->left, depth);
            /*if (node->right!=nullptr) */right_depth = recursive_tree_traversal(node->right, depth);
            cout << left_depth << " " << right_depth << endl;
            return max(left_depth, right_depth);
        };
        final_depth = recursive_tree_traversal(root, 0);
        return final_depth;
    }
};
