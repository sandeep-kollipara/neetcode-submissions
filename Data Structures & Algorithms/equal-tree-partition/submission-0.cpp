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
    bool checkEqualTree(TreeNode* root) {
        auto bfs=[](TreeNode* node){
            int total=0;
            queue<TreeNode*> q;
            q.push(node);
            while (not q.empty()){
                TreeNode* node=q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                total+=node->val;
            }
            return total;
        };
        int total = bfs(root);
        bool equal = false;
        auto dfs2=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node) return 0;
            // post-order traversal
            int left = self(self, node->left);
            int right = self(self, node->right);
            if ((node->left and total==2*left) 
            or (node->right and total==2*right)) equal=true;
            return left+right+node->val;
        };
        dfs2(dfs2, root);
        return equal;
    }
};
