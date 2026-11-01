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
    vector<int> largestValues(TreeNode* root) {
        auto bfs=[](TreeNode* node) {
            vector<int> maxrow;
            queue<TreeNode*> q;
            if (node) q.push(node);
            while (q.size()) {
                int size=q.size(), maximum=INT_MIN;
                for (int i=0; i<size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    maximum = max(maximum, node->val);
                }
                maxrow.push_back(maximum);
            }
            return maxrow;
        };
        return bfs(root);
    }
};
