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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> out;
        function<void(TreeNode*)> dfs=[&](TreeNode* node) {
            // termination
            if (node==nullptr) return ;
            // propagation
            dfs(node->left);
            dfs(node->right);
            out.push_back(node->val);
        };
        dfs(root);
        return out;
    }
};