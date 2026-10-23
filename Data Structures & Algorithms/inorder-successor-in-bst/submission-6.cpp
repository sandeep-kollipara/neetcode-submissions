class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* node = root, *prev=nullptr;
        while (node) {
            if (node->val > p->val) {
                prev = node;
                node = node->left;
            } else /*if (node->val < p->val)*/ {
                //prev = node;
                node = node->right;
            } /*else {
                break;
            }*/
        }
        //if (prev) cout << prev->val << " ";
        //if (node->right) cout << node->right->val << " ";
        /*if (prev and not node->right) */return prev;
        //return node->right;
    }
};
