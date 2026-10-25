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
                vector<TreeNode*> stk;
                for (int i=0; i<size; i++) {
                    TreeNode* node = q.front();
                    if (j%2) stk.push_back(node);
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                if (j%2) {
                    //cout << j << endl;
                    for (int i=0; i<stk.size()/2; i++) {
                        swap(stk[i]->val,stk[stk.size()-i-1]->val);
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
