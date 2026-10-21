// Node has char val, Node* left, and Node* right.
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) { 
        unordered_map<char,int> hashmap;
        auto dfs=[&](auto&& self, Node* node, bool add){
            // base case or termination
            if (not node) return ;
            // in-order traversal
            self(self, node->left, add);
            if (node->val!='+'){
                if (add) hashmap[node->val]++;
                else hashmap[node->val]--;
            }
            self(self, node->right, add);
            return ;
        };
        dfs(dfs, root1, true);
        dfs(dfs, root2, false);
        for (auto& [a,b]: hashmap) {
            if (b) return false;
        }
        return true;
    }
};
