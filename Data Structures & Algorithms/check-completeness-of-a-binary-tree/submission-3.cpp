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
    bool isCompleteTree(TreeNode* root) {
        auto bfs=[](TreeNode* node){
            bool complete=true, end=false;
            queue<TreeNode*> q;
            q.push(node);
            int i=0, size=q.size();
            while (q.size()) {
                //if (i>0) complete&=(size==pow(2,i-1)); // redundant now but works
                size=q.size();
                for (int i=0; i<size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    /*if (not node) {
                        complete=false;
                        continue;
                    }*/
                    if (node->left and node->right) { // normal course
                        if (end) complete=false;
                        q.push(node->left);
                        q.push(node->right);
                    } else if (node->left) { // possible end
                        if (end) complete=false;
                        q.push(node->left);
                        end=true;
                    } else if (node->right) { // gap found
                        complete=false;
                        q.push(node->right);
                    } else end=true; // no children
                }
                i++;
            }
            return complete;
        };
        return bfs(root);
    }
};