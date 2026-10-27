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
    struct TreeNode2 {
        TreeNode* node;
        int width;
    };
public:
    int widthOfBinaryTree(TreeNode* root) {
        auto bfs=[](TreeNode* node){
            int max_width=1;
            queue<TreeNode2> q;
            q.push({node,0});
            while (q.size()) {
                int size=q.size(), low=INT_MAX, high=INT_MIN;
                for (int i=0; i<size; i++) {
                    TreeNode* node = q.front().node;
                    int width = q.front().width;
                    low = min(low,width);
                    high = max(high,width);
                    q.pop();
                    if (node->left) q.push({node->left, 2*width});
                    if (node->right) q.push({node->right, 2*width+1});
                }
                max_width = max(max_width, high-low+1);
            }
            return max_width;
        };
        return bfs(root);
    }
};
