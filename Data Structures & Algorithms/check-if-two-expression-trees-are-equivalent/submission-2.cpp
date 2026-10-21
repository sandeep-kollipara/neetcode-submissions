// Node has char val, Node* left, and Node* right.
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) { 
        vector<int> tracker(26, 0);
        auto dfs=[&](auto&& self, Node* node, bool add){
            // base case or termination
            if (not node) return ;
            // in-order traversal
            self(self, node->left, add);
            if (node->val!='+'){
                if (add) tracker[node->val-'a']++;
                else tracker[node->val-'a']--;
            }
            self(self, node->right, add);
            return ;
        };
        dfs(dfs, root1, true);
        dfs(dfs, root2, false);
        for (int i: tracker) {
            if (i!=0) return false;
        }
        return true;
    }
};
