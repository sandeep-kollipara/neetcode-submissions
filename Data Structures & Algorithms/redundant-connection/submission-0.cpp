class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> hash_table;
        for (vector<int> edge: edges) {
            if (hash_table.find(edge[0])==hash_table.end()) hash_table[edge[0]]={edge[1]};
            else hash_table[edge[0]].push_back(edge[1]);
            if (hash_table.find(edge[1])==hash_table.end()) hash_table[edge[1]]={edge[0]};
            else hash_table[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        function<vector<int>(int,int,vector<int>)> dfs_graph=[&](int i, int j, vector<int> path) {
            path.push_back(i);
            if (visited.find(i)==visited.end()) { // new node, proliferation
                visited.insert(i);
                vector<int> result, split;
                for (int k: hash_table[i]) {
                    if (/*visited.find(k)==visited.end() and */k!=j) split = dfs_graph(k, i, path);
                    else continue;
                    if (result.size()==0) result.insert(result.end(), split.begin(), split.end());
                }
                return result;
            }
            else { //cycle detected, return path
                return path;
            }
        };
        vector<int> cycle_path = dfs_graph(1, 1, {});
        for (int i: cycle_path) cout << cycle_path[i] << " ";
        cout << endl;
        int duplicate = cycle_path[cycle_path.size()-1];
        cycle_path = vector<int>(find(cycle_path.begin(), cycle_path.end()-1, duplicate), cycle_path.end());
        int x, y;
        for (int i=edges.size()-1; i>-1; i--) {
            x = edges[i][0];
            y = edges[i][1];
            if (find(cycle_path.begin(),cycle_path.end(),x)!=cycle_path.end() 
            and find(cycle_path.begin(),cycle_path.end(),y)!=cycle_path.end()) break;
        }
        return vector<int>({x,y});
        //return vector<int>({1,0});
    }
};
