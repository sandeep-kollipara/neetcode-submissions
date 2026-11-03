class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> hashset(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node) return (TreeNode*)nullptr;
            // post-order traversal
            TreeNode* left = self(self, node->left);
            node->left = left;
            TreeNode* right = self(self, node->right);
            node->right = right;
            if (hashset.count(node->val)) {
                if (left) forest.push_back(left);
                if (right) forest.push_back(right);
                delete node;
                return (TreeNode*)nullptr;
            }
            return node;
        };
        if (root and not hashset.count(root->val)) forest.push_back(root);
        dfs(dfs, root);
        return forest;
    }
};
