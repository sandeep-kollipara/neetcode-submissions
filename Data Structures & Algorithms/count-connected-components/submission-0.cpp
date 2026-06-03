class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> hash_table;
        for (vector<int> edge: edges) {
            if (hash_table.find(edge[0])==hash_table.end()) hash_table[edge[0]] = {edge[1]};
            else hash_table[edge[0]].push_back(edge[1]);
            if (hash_table.find(edge[1])==hash_table.end()) hash_table[edge[1]] = {edge[0]};
            else hash_table[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        function<void(int)> dfs_graph=[&](int i/*current*/){
            visited.insert(i);
            if (hash_table.find(i)==hash_table.end()) return ; // initial termination
            else {
                for (int j: hash_table[i]) {
                    if (visited.find(j)==visited.end()) dfs_graph(j);
                    else continue;
                }
            }
        };
        int i=0, connected_components=0;
        while (i < n) {
            if (visited.find(i)==visited.end()) {
                dfs_graph(i);
                connected_components++;
            }
            i++;
        }
        return connected_components;
    }
};
