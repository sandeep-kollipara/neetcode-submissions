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
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> arrmap(10, 0); // 0 - unused, 1-9 - used
        int odd=0, even=9, palindrome=0;
        auto add_num=[&](int i){
            if ((++arrmap[i])%2) {odd++; even--;}
            else {even++; odd--;}
        };
        auto remove_num=[&](int i){
            if ((--arrmap[i])%2) {odd++; even--;}
            else {even++; odd--;}
        };
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node) return ;
            // pre-order traversal
            add_num(node->val);
            if (not node->left and not node->right) {
                if (odd<=1) palindrome++;
            }
            self(self, node->left);
            self(self, node->right);
            remove_num(node->val);
            return ;
        };
        dfs(dfs, root);
        return palindrome;
    }
};
