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
    vector<vector<int>> levelOrder(TreeNode* root) {
        function<vector<vector<int>>(TreeNode*)> level_order_traversal=[](TreeNode* node){
            queue<TreeNode*> q = {};
            q.push(node);
            vector<vector<int>> full_list = {};
            int depth=0, j=1;
            while (not q.empty()){ // depth-level
                int i=0, k=0;
                TreeNode* curr = nullptr;
                vector<int> level_list = {};
                while (i<j and not q.empty()){ // node-level
                    // last level termination
                    if (q.empty()) break;
                    // processing the queue
                    curr = q.front();
                    q.pop();
                    // edge case - []
                    if (curr==nullptr) continue;
                    // updating the queue
                    level_list.insert(level_list.end(), curr->val);
                    if (curr->left!=nullptr) {
                        q.push(curr->left);
                        k++;
                    }
                    if (curr->right!=nullptr) {
                        q.push(curr->right);
                        k++;
                    }
                    i++;
                    cout << i << endl;
                }
                j = k;
                if (i!=0) full_list.insert(full_list.end(), level_list);
                depth++;
            }
            return full_list;
        };
        return level_order_traversal(root);
    }
};
