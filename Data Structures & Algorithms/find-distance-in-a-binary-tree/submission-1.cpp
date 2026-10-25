class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        // find lowest common ancestor
        bool found=false;
        TreeNode* lca=nullptr, *pnode, *qnode;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node or found) return 0;
            // post-order traversal
            int left = self(self, node->left);
            int right = self(self, node->right);
            int center=0;
            if (node->val==p) {
                pnode = node;
                center++;
            }
            if (node->val==q) {
                qnode = node;
                center++;
            }
            if (not found and center+left+right==2) {
                found = true;
                lca = node;
            }
            return center+left+right;
        };
        dfs(dfs, root);
        //cout << lca->val << endl;
        // calculate their depths from lca and add
        int height1=-1, height2=-1;
        found=false;
        auto dfs2=[&](auto&& self, TreeNode* node, int depth){
            // base case or termination
            if (not node or found) return ;
            // traversal
            self(self, node->left, depth+1);
            self(self, node->right, depth+1);
            if (node==pnode) height1=depth;
            if (node==qnode) height2=depth;
            if (height1>=0 and height2>=0) found=true;
            return ;
        };
        dfs2(dfs2, lca, 0);
        return height1 + height2;
    }
};
