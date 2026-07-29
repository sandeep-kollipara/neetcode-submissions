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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial;
        auto preorder_dfs_serial=[&](auto&& self, TreeNode* node, int depth) {
            // base case or termination
            if (node==nullptr) {
                for (int i=0; i<depth; i++) serial+='-';
                serial+="99999";
                return ;
            }
            // traversal
            for (int i=0; i<depth; i++) serial+='-';
            serial+=to_string(node->val);
            self(self, node->left, depth+1);
            self(self, node->right, depth+1);
            return ;
        };
        preorder_dfs_serial(preorder_dfs_serial, root, 0);
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Reusing the solution from 1028. Recover a Tree from Preorder Traversal
        string traversal = data;
        struct Trio{
            int first;
            int second;
            int third;
            Trio(int a, int b, int c){
                first=a;
                second=b;
                third=c;
            }
        };
        auto check_next=[&](int i){
            int depth=0, val;
            while(i<traversal.size() and traversal[i]=='-') {
                depth++;
                i++;
            }
            string s;
            while(i<traversal.size() and traversal[i]!='-') {
                s+=traversal[i];
                i++;
            }
            val = stoi(s);
            return Trio(depth, val, i); 
        };
        auto preorder_dfs=[&](auto&& self, int i, int depth){
            if (i==traversal.size()) return make_pair((TreeNode*)nullptr, i);
            Trio t = check_next(i);
            // base case or termination
            if (depth!=t.first) return make_pair((TreeNode*)nullptr, i);
            // traversal
            TreeNode* node = new TreeNode(t.second);
            i = t.third;
            if (t.second==99999) return make_pair((TreeNode*)nullptr, i); // extra step
            pair<TreeNode*, int> p = self(self, i, depth+1);
            node->left = p.first;
            i = p.second;
            pair<TreeNode*, int> q = self(self, i, depth+1);
            node->right = q.first;
            i = q.second;
            return make_pair(node, i);
        };
        pair<TreeNode*, int> r = preorder_dfs(preorder_dfs, 0, 0);
        TreeNode* root = r.first; 
        return root;
    }
};
