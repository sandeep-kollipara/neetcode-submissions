class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        // find lowest common ancestor
        bool found=false;
        TreeNode* lca=nullptr;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node or found) return 0;
            // post-order traversal
            int left = self(self, node->left);
            int right = self(self, node->right);
            int center = (node->val==p) ? 1 : 0;
            center += (node->val==q) ? 1 : 0;
            if (not found and center+left+right==2) {
                found = true;
                lca = node;
            }
            return center+left+right;
        };
        dfs(dfs, root);
        //cout << lca->val << endl;
        // calculate their depths from lca and add
        int depth=0, height1=-1, height2=-1;
        queue<TreeNode*> qu;
        qu.push(lca);
        while(qu.size()) {
            int sz = qu.size();
            for (int i=0; i<sz; i++) {
                // extract from queue
                TreeNode* node = qu.front();
                qu.pop();
                // insert into queue
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
                if (node->val==p) height1 = depth;
                if (node->val==q) height2 = depth;

            }
            if (height1>=0 and height2>=0) break;
            depth++;
        }
        return height1 + height2;
    }
};
