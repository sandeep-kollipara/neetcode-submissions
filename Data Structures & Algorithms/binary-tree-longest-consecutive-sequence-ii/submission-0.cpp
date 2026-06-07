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
    int longestConsecutive(TreeNode* root) {
        unordered_map<TreeNode*,int> hashmap;
        int maxlen=0;
        auto preorder_dfs1=[&](auto&& self, TreeNode* node) {
            // termination
            if (node==nullptr) return make_pair(100000, 0);
            // traversal
            int len = 1;
            pair<int,int> left_pair = self(self, node->left);
            pair<int,int> right_pair = self(self, node->right);
            if (node->val - left_pair.first == 1) len = max(left_pair.second + 1, len);
            if (node->val - right_pair.first == 1) len = max(right_pair.second + 1, len);
            hashmap[node]+=len;
            return make_pair(node->val, len);
        };
        auto preorder_dfs2=[&](auto&& self, TreeNode* node) {
            // termination
            if (node==nullptr) return make_pair(100000, 0);
            // traversal
            int len = 1;
            pair<int,int> left_pair = self(self, node->left);
            pair<int,int> right_pair = self(self, node->right);
            if (node->val - left_pair.first == -1) len = max(left_pair.second + 1, len);
            if (node->val - right_pair.first == -1) len = max(right_pair.second + 1, len);
            hashmap[node]+=len;
            return make_pair(node->val, len);
        };
        preorder_dfs1(preorder_dfs1, root);
        preorder_dfs2(preorder_dfs2, root);
        for (auto [a, b] : hashmap) if (b>maxlen) maxlen = b;
        return maxlen-1;
    }
};
