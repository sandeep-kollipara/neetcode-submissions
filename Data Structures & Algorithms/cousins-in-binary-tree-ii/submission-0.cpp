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
    TreeNode* replaceValueInTree(TreeNode* root) {
        auto bfs=[](TreeNode* node){
            queue<TreeNode*> q;
            q.push(node);
            int old_sum = 10*node->val;
            node->val = 5*node->val;
            while (q.size()) {
                int size = q.size(), new_sum=0;
                for (int i=0; i<size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    if (node->left) new_sum+=10*node->left->val;
                    if (node->right) new_sum+=10*node->right->val;
                    node->val = old_sum/10 - node->val/5;
                    if (node->left and node->right) {
                        int family_sum = node->left->val + node->right->val;
                        node->left->val = node->right->val = family_sum*5;
                    } else if (node->left) node->left->val*=5;
                    else if (node->right) node->right->val*=5;
                }
                old_sum = new_sum;
            }
            return ;
        };
        bfs(root);
        return root;
    }
};
