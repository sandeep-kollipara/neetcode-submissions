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
    bool isEvenOddTree(TreeNode* root) {
        auto bfs=[](TreeNode* node){
            queue<TreeNode*> q;
            q.push(node);
            int j=0;
            while (q.size()) {
                int size=q.size(), prev;
                if (j%2) prev=INT_MAX;
                else prev=INT_MIN;
                for (int i=0; i<size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    if ((j%2 and node->val%2)
                    or (j%2==0 and node->val%2==0)) return false;
                    if ((j%2 and prev<=node->val)
                    or (j%2==0 and prev>=node->val)) return false;
                    prev=node->val;
                }
                j++;
            }
            return true;
        };
        return bfs(root);
    }
};
