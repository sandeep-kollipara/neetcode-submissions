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
    string smallestFromLeaf(TreeNode* root) {
        auto cmp=[](string a, string b){
            int i=a.length()-1, j=b.length()-1, k=0;
            while (k<=min(i,j)) {
                if (a[i-k] < b[j-k]) return false;
                else if (a[i-k] > b[j-k]) return true;
                k++;
            }
            if (a.length() < b.length()) return false;
            return true;
        };
        priority_queue<string, vector<string>, decltype(cmp)> minheap(cmp);
        auto dfs=[&](auto&& self, TreeNode* node, string r){
            // base case or termination
            if (not node) return ;
            // pre-order traversal
            r+=('a'+node->val);
            if (not node->left and not node->right) minheap.push(r);
            self(self, node->left, r);
            self(self, node->right, r);
            return ;
        };
        dfs(dfs, root, "");
        string s = minheap.top();
        reverse(s.begin(), s.end());
        return s;
    }
};
