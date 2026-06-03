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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        function<TreeNode*(vector<int>, vector<int>)> recursive_tree_traversal=[&](vector<int> preorder_arr, vector<int> inorder_arr){
            TreeNode* center = nullptr;
            int center_val;
            cout << "Preorder:" << endl;
            for (int i: preorder_arr) cout << i << " ";
            cout << endl;
            cout << "Inorder:" << endl;
            for (int i: inorder_arr) cout << i << " ";
            cout << endl;
            // find the center (root)
            if (preorder_arr.size()!=0) center_val = preorder_arr[0];
            else return center;
            // divide the arrays based on center's location
            int delta = distance(inorder_arr.begin(), find(inorder_arr.begin(), inorder_arr.end(), center_val));
            cout << "Delta:" << delta << endl;
            vector<int> preorder_left, preorder_right, inorder_left, inorder_right;
            preorder_left = vector<int>(preorder_arr.begin()+1, preorder_arr.begin()+1+delta);
            preorder_right = vector<int>(preorder_arr.begin()+delta+1, preorder_arr.end());
            inorder_left = vector<int>(inorder_arr.begin(), inorder_arr.begin()+delta);
            inorder_right = vector<int>(inorder_arr.begin()+delta+1, inorder_arr.end());
            // recurse through each of the subarrays - connect the returned node to the center
            TreeNode* left = recursive_tree_traversal(preorder_left, inorder_left);
            TreeNode* right = recursive_tree_traversal(preorder_right, inorder_right);
            center = new TreeNode(center_val, left, right);
            // return the center's address
            return center;
        };
        return recursive_tree_traversal(preorder, inorder);
    }
};
