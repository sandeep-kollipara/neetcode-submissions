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
    bool isBalanced(TreeNode* root) {
        function<pair<int,bool>(TreeNode*)> depth_first_search=[&](TreeNode* node){
            pair<int,bool> left_pair, right_pair;
            int delta, max_depth;
            // termination at leaves
            if (node==nullptr) return pair<int,bool>({-1,true});
            // recursion for non-leaves
            left_pair = depth_first_search(node->left);
            right_pair = depth_first_search(node->right);
            delta = abs(left_pair.first - right_pair.first);
            max_depth = max(left_pair.first+1, right_pair.first+1);
            // exit
            if (delta > 1 or not left_pair.second or not right_pair.second) return pair<int,bool>({max_depth,false});
            else return pair<int,bool>({max_depth,true});
        };
        return depth_first_search(root).second;
    }
};
