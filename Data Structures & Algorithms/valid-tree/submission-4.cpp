class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size()==0 and n==1) return true; // edge case when only root is present
        unordered_map<int,vector<int>> hash_table;
        for (vector<int> edge: edges){
            if (edge[0]==edge[1]) return false; // edge case when there is a self loop
            if (hash_table.find(edge[0])==hash_table.end()) hash_table[edge[0]] = {edge[1]};
            else hash_table[edge[0]].push_back(edge[1]);
            if (hash_table.find(edge[1])==hash_table.end()) hash_table[edge[1]] = {edge[0]};
            else hash_table[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        function<bool(int,int,unordered_set<int>)> dfs_graph=[&](int i, int j, unordered_set<int> hash_set) {
            bool result=true;
            if (hash_table.find(i)==hash_table.end()
            and hash_set.find(i)==hash_set.end()) return false; // disconnected
            else if (hash_table.find(i)!=hash_table.end()
            and hash_set.find(i)==hash_set.end()) { // new node, path update and proliferate
                hash_set.insert(i);
                visited.insert(i);
                for (int k: hash_table[i]) {
                    if (k==j) continue;
                    else result = result and dfs_graph(k, i, hash_set);
                }
            }
            else if (hash_table.find(i)!=hash_table.end()
            and hash_set.find(i)!=hash_set.end()) { // cycle
                return false;
            }
            return result;
        };
        return dfs_graph(0,0,{}) and visited.size()==n;
    }
};
