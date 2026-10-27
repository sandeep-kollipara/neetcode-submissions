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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        auto zzbfs=[](TreeNode* node){
            vector<vector<int>> out;
            if (not node) return out;
            stack<TreeNode*> stk1, stk2;
            int i=0;
            stk2.push(node);
            while (stk1.size() or stk2.size()) {
                vector<int> level;
                int size;
                stack<TreeNode*>* stk_a, *stk_b;
                if (i%2) {
                    stk_a=&stk1;
                    stk_b=&stk2;
                } else {
                    stk_a=&stk2;
                    stk_b=&stk1;
                }
                size=stk_a->size();
                //cout<< size << endl;
                for (int j=0; j<size; j++) {
                    TreeNode* node = stk_a->top();
                    stk_a->pop();
                    if (i%2) {
                        if (node->right) stk_b->push(node->right);
                        if (node->left) stk_b->push(node->left);
                    } else {
                        if (node->left) stk_b->push(node->left);
                        if (node->right) stk_b->push(node->right);
                    }
                    level.push_back(node->val);
                }
                out.push_back(level);
                i++;
            }
            return out;
        };
        return zzbfs(root);
    }
};