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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        auto bfs=[](TreeNode* node){
            if (not node) return node;
            queue<TreeNode*> q;
            q.push(node);
            TreeNode* prev = nullptr, *root2=nullptr;
            while (q.size()){
                int size = q.size();
                for (int i=0; i<size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                    if (i==0) {
                        node->right = prev;
                        node->left = nullptr;
                        prev = node;
                        root2 = node;
                    } else {
                        prev->left = node;
                    }
                }
            }
            return root2;
        };
        return bfs(root);
    }
};
