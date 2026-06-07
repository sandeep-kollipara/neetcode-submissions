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
    double maximumAverageSubtree(TreeNode* root) {
        double max_avg = 0;
        auto postorder_dfs=[&](auto&& self, TreeNode* node) {
            // termination
            if (node==nullptr) return make_pair(0,0);
            // traversal
            pair<int,int> left_pair = self(self, node->left);
            pair<int,int> right_pair = self(self, node->right);
            int count = left_pair.second + right_pair.second + 1;
            int total = left_pair.first + right_pair.first + node->val;
            double avg = (double)total/count;
            cout << avg << endl;
            if (avg > max_avg) max_avg = avg;
            return make_pair(total, count);
        }; // returns total, count
        postorder_dfs(postorder_dfs, root);
        return max_avg;
    }
};
