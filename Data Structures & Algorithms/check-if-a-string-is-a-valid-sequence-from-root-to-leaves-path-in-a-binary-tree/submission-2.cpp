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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        auto dfs=[&](auto&& self, TreeNode* node, int i){
            // base case or termination
            if (not node or i>=arr.size()) return false;
            // pre-order traversal
            if (i+1==arr.size() and arr[i]==node->val and not node->left and not node->right) return true;
            else if (arr[i]!=node->val) return false;
            bool left=self(self, node->left, i+1);
            bool right=self(self, node->right, i+1);
            return left or right;
        };
        return dfs(dfs,root,0);
    }
};
