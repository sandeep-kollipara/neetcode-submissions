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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (not root1 and not root2) return true;
        else if (not root1 or not root2) return false;
        bool out=(root1->val==root2->val);
        auto bidfs=[&](auto&& self, TreeNode* node1, TreeNode* node2){
            // base case or termination
            if (not out) return ;
            else if (not node1 and not node2) return ; // leaves
            else if (not node1 or not node2) { // semi leaves
                out=false;
                return ;
            }
            // pre-order traversal
            if (((not node1->left and not node2->left) or
            (node1->left and node2->left 
            and node1->left->val==node2->left->val))
            and ((not node1->right and not node2->right) or 
            (node1->right and node2->right 
            and node1->right->val==node2->right->val))) {
                self(self, node1->left, node2->left);
                self(self, node1->right, node2->right);
            } else if (((not node1->left and not node2->right) or
            (node1->left and node2->right 
            and node1->left->val==node2->right->val))
            and ((not node1->right and not node2->left) or 
            (node1->right and node2->left 
            and node1->right->val==node2->left->val))) {
                self(self, node1->left, node2->right);
                self(self, node1->right, node2->left);
            } else {
                out=false;
                return ;
            }
        };
        bidfs(bidfs, root1, root2);
        return out;
    }
};
