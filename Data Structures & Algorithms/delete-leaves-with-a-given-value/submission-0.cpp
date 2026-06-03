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
    TreeNode* removeLeafNodes(TreeNode* root, int target) { // post-order traversal
        function<TreeNode*(TreeNode*)> dfs=[&](TreeNode* node) {
            // termination
            if (node==nullptr) return node;
            // proliferation
            node->left=dfs(node->left);
            node->right=dfs(node->right);
            // processing
            if (node->val==target and node->left==nullptr and node->right==nullptr) {
                delete node;
                return (TreeNode*)nullptr;
            } else return node;
        };
        return dfs(root);
    }
};