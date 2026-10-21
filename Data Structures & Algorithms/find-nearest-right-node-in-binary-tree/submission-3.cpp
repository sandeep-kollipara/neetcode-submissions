class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q;
        q.push(root);
        // bfs
        while (q.size()){
            int width = q.size();
            for (int i=0; i<width; i++) {
                TreeNode* node = q.front();
                q.pop();
                // base case or termination
                ;
                // level-order traversal
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (node==u) {
                    return (i+1<width)?q.front():nullptr;
                }
            }
        }
        return nullptr;
    }
};
