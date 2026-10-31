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
    int findBottomLeftValue(TreeNode* root) {
        auto bfs=[](auto&& self, TreeNode* node){
            queue<TreeNode*> q;
            q.push(node);
            int first=-1;
            while (q.size()) {
                int size=q.size();
                for (int i=0; i<size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    if (i==0) first=node->val;
                }
            }
            return first;
        };
        return bfs(bfs, root);
    }
};
