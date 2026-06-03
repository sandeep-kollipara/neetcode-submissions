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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca;
        pair<bool, bool> pq_found = {false, false};
        function<pair<bool, bool>(TreeNode*, pair<bool, bool>)> recursive_tree_traversal=[&](TreeNode* node, pair<bool, bool> flags){
            bool p_found=false, q_found=false;
            if (node==nullptr) return flags; // Endpoints
            else if (node==p) flags.first=true; // Node p found
            else if (node==q) flags.second=true; // Node q found
            pair<bool, bool> flags_left = recursive_tree_traversal(node->left, flags);
            pair<bool, bool> flags_right = recursive_tree_traversal(node->right, flags);
            flags = {flags_left.first or flags_right.first, flags_left.second or flags_right.second};
            if (flags.first and flags.second) {
                if (node==p) lca = q;
                else if (node==q) lca = p;
                else lca = node;
                flags.first = flags.second = false;
            }
            return flags;
        };
        recursive_tree_traversal(root, pq_found);
        return lca;
    }
};
