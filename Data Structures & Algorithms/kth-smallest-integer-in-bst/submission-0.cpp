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
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<int, int> hash_map = {};
        int i=0;
        function<void(TreeNode*)> recursive_tree_traversal=[&](TreeNode* node){
            if (node==nullptr) return;
            recursive_tree_traversal(node->left);
            i++;
            hash_map[i] = node->val;
            recursive_tree_traversal(node->right);
        };
        recursive_tree_traversal(root);
        return hash_map[k];
    }
};
