class Solution {
    struct TreeNode{
        int idx, val;
        vector<TreeNode*> children;
        TreeNode(int i, int v): idx(i), val(v) {}
    };
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<TreeNode*> tree;
        for (int i=0; i<value.size(); i++) {
            TreeNode* neuva = new TreeNode(i,value[i]);
            tree.push_back(neuva);
        }
        for (int i=1; i<parent.size(); i++) {
            tree[parent[i]]->children.push_back(tree[i]);
        }
        int deleted=0;
        auto dfs=[&](auto&& self, TreeNode* node){
            // base case or termination
            if (not node) return pair<int,int>({0,0});
            // post-order traversal
            pair<int,int> total = {0,0};
            for (auto& child: node->children) {
                pair<int,int> out = self(self, child);
                total.first+=out.first;
                total.second+=out.second;
            }
            total.first+=node->val;
            total.second++;
            if (total.first==0) {
                deleted+=total.second;
                total = {0,0};
            }
            return total;
        };
        pair<int,int> out = dfs(dfs, tree[0]);
        return out.second;
    }
};
