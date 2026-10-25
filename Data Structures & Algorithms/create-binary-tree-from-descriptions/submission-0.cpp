class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // create a hashmap of node values to new nodes
        // and process each node pairs by connecting the pointers
        unordered_map<int,TreeNode*> hashmap;
        for (auto& v: descriptions) {
            if (not hashmap.count(v[0])) hashmap[v[0]] = new TreeNode(v[0]);
            if (not hashmap.count(v[1])) hashmap[v[1]] = new TreeNode(v[1]);
            if (v[2]) hashmap[v[0]]->left = hashmap[v[1]];
            else hashmap[v[0]]->right = hashmap[v[1]];
        }
        // make a pass on descriptions and finding the root 
        // by deleting the entry of the children in hashmap (leftover is root)
        for (auto& v: descriptions) {
            hashmap.erase(v[1]);
        }
        if (hashmap.size()==1){
            for (auto& [a,b]: hashmap) {
                return b;
            }
        }
        return nullptr;
    }
};
