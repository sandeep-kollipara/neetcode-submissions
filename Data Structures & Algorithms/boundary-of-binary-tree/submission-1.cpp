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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        auto custom_dfs=[](auto&& self, TreeNode* node, bool left, bool right, bool breaker, vector<int>& boundary){
            // base case or termination
            if (node==nullptr) return ;
            // traversal - save the leftmost and rightmost on all depths + all leaves
            // maintenance
            bool right1=false, left2=false, leaf=false, breaker2=false;
            if (node->left==nullptr and node->right==nullptr) leaf=true;
            else if (node->left==nullptr and left) left2=true;
            else if (node->right==nullptr and right) right1=true;
            // first visit - root and left boundary
            if ((left and !right and not leaf) 
            or (left and right and breaker and not leaf)) boundary.push_back(node->val);
            if (left and right1) breaker2=true;
            self(self, node->left, left, right1, breaker2, boundary);
            breaker2=false;
            // second visit - leaf
            if (leaf) boundary.push_back(node->val);
            if (left2 and right) breaker2=false;
            self(self, node->right, left2, right, breaker2, boundary);
            // last visit - right boundary
            if (right and !breaker and not leaf) boundary.push_back(node->val);
            return ;
        };
        vector<int> bound;
        custom_dfs(custom_dfs, root, true, true, true, bound);
        //bound.pop_back();
        return bound;
    }
};
