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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        int minimum=0, maximum=0;
        unordered_map<int,vector<int>> hashmap;
        /*auto preorder_dfs=[&](auto&& self, TreeNode *node, int index){
            // termination
            if (node==nullptr) return;
            // pre-order traversal
            hashmap[index].push_back(node->val);
            if (index > maximum) maximum = index;
            if (index < minimum) minimum = index;
            self(self, node->left, index-1);
            self(self, node->right, index+1);
            return ;
        };*/
        //preorder_dfs(preorder_dfs, root, 0);
        struct Node {
            TreeNode *treenode;
            int index;
            Node(TreeNode* a, int b): treenode(a), index(b) {}
        };
        list<Node*> ll;
        if (root==nullptr) return vector<vector<int>>(0);
        Node* node = new Node(root, 0);
        ll.push_back(node);
        while(!ll.empty()) {
            node = ll.front();
            ll.pop_front();
            int index = node->index;
            TreeNode* treenode = node->treenode;
            hashmap[index].push_back(treenode->val);
            if (index > maximum) maximum = index;
            if (index < minimum) minimum = index;
            if (treenode->left!=nullptr) {
                Node *left = new Node(treenode->left, index-1);
                ll.push_back(left);
            }
            if (treenode->right!=nullptr) {
                Node *right = new Node(treenode->right, index+1);
                ll.push_back(right);
            }
        }
        vector<vector<int>> result;
        for (int i=minimum; i<=maximum; i++) {
            result.push_back(hashmap[i]);
        }
        return result;
    }
};