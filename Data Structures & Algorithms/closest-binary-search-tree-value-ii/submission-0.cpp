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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // inorder traversal of dfs with sliding window of k size (sum of distance)
        queue<int> q;
        float sum=0, min_sum=INT_MAX, q_front=INT_MIN;
        auto inorder_dfs1=[&](auto&& self, TreeNode* node) {
            // base case or termination
            if (node==nullptr) return ;
            // traversal
            self(self, node->left);
            q.push(node->val);
            sum+=(abs(target-(float)node->val));
            if (q.size()>k) {
                int pop = q.front();
                sum-=(abs(target-(float)pop));
                q.pop();
            }
            if (q.size()==k and sum < min_sum) {
                min_sum = sum;
                q_front = q.front();
            }
            self(self, node->right);
            return ;
        };
        inorder_dfs1(inorder_dfs1, root);
        cout << q_front << endl;
        vector<int> out;
        auto inorder_dfs2=[&](auto&& self, TreeNode* node) {
            // base case or termination
            if (node==nullptr) return ;
            // traversal
            self(self, node->left);
            if ((node->val==q_front or out.size()) and out.size()<k) out.push_back(node->val);
            self(self, node->right);
            return ;
        };
        inorder_dfs2(inorder_dfs2, root);
        return out;
    }
};
