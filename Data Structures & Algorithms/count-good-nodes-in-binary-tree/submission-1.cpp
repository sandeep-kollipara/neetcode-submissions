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
    int goodNodes(TreeNode* root) {
        int good_nodes_counter=0;
        function<void(TreeNode*, int)> dfs=[&](TreeNode* node, int max_so_far) {
            if (node==nullptr) return ;
            if (node->val >= max_so_far) {
                good_nodes_counter++;
                max_so_far = node->val;
            }
            dfs(node->left, max_so_far);
            dfs(node->right, max_so_far);
        };
        dfs(root, -101);
        return good_nodes_counter;
    }
};
