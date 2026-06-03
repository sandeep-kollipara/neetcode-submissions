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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> hash_map_2b, hash_map_not2b;
        function<int(bool, TreeNode*)> recurse=[&](bool rob, TreeNode* node) {
            // termination
            if (node==nullptr) return 0;
            if (rob and hash_map_2b.find(node)!=hash_map_2b.end()) return hash_map_2b[node];
            if (!rob and hash_map_not2b.find(node)!=hash_map_not2b.end()) return hash_map_not2b[node];
            // proliferation and processing
            if (rob) {
                hash_map_2b[node] = recurse(false, node->left) + recurse(false, node->right);
                return hash_map_2b[node];
            } else {
                hash_map_not2b[node] = max(recurse(true, node->left)+recurse(true, node->right)+node->val, 
                recurse(false, node->left)+recurse(false, node->right));
                return hash_map_not2b[node];
            }
        };
        return recurse(false, root);
    }
};