class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int depth, reached=INT_MAX;
        bool found;
        // bfs
        while (q.size()){
            TreeNode* node = q.front().first;
            int depth=q.front().second;
            q.pop();
            // base case or termination
            if (not node) continue;
            // level-order traversal
            q.push({node->left,depth+1});
            q.push({node->right,depth+1});
            if (found and depth==reached) return node;
            if (node==u) {
                reached=depth;
                found=true;
            }
        }
        return nullptr;
    }
};
