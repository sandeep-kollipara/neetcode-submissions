class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        auto verify=[](auto&& self, TreeNode* node, ListNode* node2)->bool{
            if (not node2) return true;
            else if (not node) return false;
            if (node2->val==node->val) 
                return self(self, node->left, node2->next) 
                or self(self, node->right, node2->next);
            return false;
        };
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node) return false;
            // pre-order traversal
            bool match=false;
            match|=verify(verify, node, head);
            match|=self(self, node->left);
            match|=self(self, node->right);
            return match;
        };
        return dfs(dfs, root);
    }
};
