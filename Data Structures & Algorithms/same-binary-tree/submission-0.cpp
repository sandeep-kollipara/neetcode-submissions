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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        function<bool(TreeNode*, TreeNode*)> compare_two_trees=[&](TreeNode* a, TreeNode* b){
            if (a==nullptr and b == nullptr) return true;
            else if (a==nullptr or b == nullptr) return false;
            if (a->val != b->val) return false;
            bool left_branch = compare_two_trees(a->left, b->left);
            bool right_branch = compare_two_trees(a->right, b->right);
            return (left_branch and right_branch);
        };
        return compare_two_trees(p, q);
    }
};
