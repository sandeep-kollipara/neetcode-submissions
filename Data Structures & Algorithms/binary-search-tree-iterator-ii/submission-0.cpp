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
class BSTIterator {
    int i=0;
    vector<int> arr;
public:
    BSTIterator(TreeNode* root) {
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node) return ;
            // in-order traversal
            self(self, node->left);
            arr.push_back(node->val);
            self(self, node->right);
            return ;
        };
        arr.push_back(INT_MIN);
        dfs(dfs, root);
    }
    int next() { 
        return arr[++i];
    }
    bool hasNext() {
        return i+1<arr.size();
    }
    int prev() { 
        return arr[--i];
    }
    bool hasPrev() { 
        return i-1>0; // 0 index is for initial position
    }
};
