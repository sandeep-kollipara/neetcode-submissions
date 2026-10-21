class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        int reached=INT_MAX;
        bool found=false;
        TreeNode* out=nullptr;
        auto dfs=[&](auto&& self, TreeNode* node, int depth){
            // base case or termination
            if (not node or found or depth>reached) return ;
            // pre-order traversal (setting reached first is optimal)
            if (not found and depth==reached) {
                out=node;
                found=true;
            }
            if (node==u) reached=depth;
            self(self, node->left, depth+1);
            self(self, node->right, depth+1);
            return ;
        };
        dfs(dfs, root, 0);
        return out;
    }
};
