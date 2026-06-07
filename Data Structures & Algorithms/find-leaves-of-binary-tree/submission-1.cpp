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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) return -1;
            
            int leftDepth = dfs(node->left);
            int rightDepth = dfs(node->right);
            int depth = max(leftDepth, rightDepth) + 1;
            
            if (result.size() == depth) {
                result.push_back({});
            }
            result[depth].push_back(node->val);
            
            return depth;
        };
        
        dfs(root);
        return result;
    }
};