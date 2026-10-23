class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
        unordered_set<TreeNode*> hashset;
        for (TreeNode* i: nodes) hashset.insert(i);
        bool found=false;
        TreeNode* lca=nullptr;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case
            if (not node) return 0;
            // post-order traversal -> necessary for first sum to be LCA
            int left = self(self, node->left);
            int right = self(self, node->right);
            int center = 0;
            if (hashset.find(node)!=hashset.end()) center++;
            if (not found and left+right+center==hashset.size()) {
                found=true;
                lca = node;
                //cout << node->val;
            }
            return left+right+center;
        };
        dfs(dfs, root);
        return lca;
    }
};
