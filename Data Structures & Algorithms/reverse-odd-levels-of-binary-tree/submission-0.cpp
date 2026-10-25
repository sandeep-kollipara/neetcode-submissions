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
    TreeNode* reverseOddLevels(TreeNode* root) {
        auto bfs=[](TreeNode* node){
            queue<TreeNode*> q;
            q.push(node);
            int j=0;
            while (not q.empty()) {
                int size = q.size();
                stack<TreeNode*> stk;
                queue<int> q2;
                for (int i=0; i<size; i++) {
                    TreeNode* node = q.front();
                    if (j%2) {
                        stk.push(node);
                        q2.push(node->val);
                    }
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                if (j%2) {
                    //cout << j << endl;
                    while (stk.size()) {
                        stk.top()->val = q2.front();
                        stk.pop();
                        q2.pop();
                    }
                }
                j++;
            }
            return ;
        };
        bfs(root);
        return root;
    }
};
