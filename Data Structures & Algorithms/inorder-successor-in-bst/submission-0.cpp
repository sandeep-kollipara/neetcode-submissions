class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        int curr=-1, prev=-1;
        TreeNode* next = nullptr;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case
            if (node==nullptr) return ;
            // in-order traversal
            self(self, node->left);
            prev = curr;
            curr = node->val;
            if (prev==p->val) next=node;
            self(self, node->right);
            return ;
        };
        dfs(dfs, root);
        return next;
    }
};
