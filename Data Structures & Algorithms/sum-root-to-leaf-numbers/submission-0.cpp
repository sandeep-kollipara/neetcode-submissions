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
    int sumNumbers(TreeNode* root) {
        int sum=0;
        auto dfs=[&](auto&& self, TreeNode* node, string s){
            // base case or termination
            if (not node) return ;
            // pre-order traversal
            s+=to_string(node->val);
            if (not node->left and not node->right) { // leaf
                sum+=stoi(s);
            }
            self(self, node->left, s);
            self(self, node->right, s);
            return ;
        };
        dfs(dfs, root, "");
        return sum;
    }
};