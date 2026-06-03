class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // DAG and cycle detection
        unordered_map<int,vector<int>> hash_table;
        vector<int> sources;
        for (vector<int> vec: prerequisites) {
            int sink=vec[0], source=vec[1];
            if (hash_table.find(source)!=hash_table.end()) hash_table[source].push_back(sink);
            else hash_table[source]={sink};
            sources.push_back(source);
        }
        while(!sources.empty()) { // depth first search
            bool first_sight=false;
            int source = sources[0];
            sources.erase(sources.begin());
            function<bool(int, unordered_set<int>)> dfs=[&](int i, unordered_set<int> hash_set){
                bool result = true;
                // did we encounter before?
                if (hash_set.find(i)==hash_set.end()) hash_set.insert(i);
                else return false;
                // proliferate based on prerequisites
                if (hash_table.find(i)!=hash_table.end()) {
                    for (int j: hash_table[i]) result = (result and dfs(j, hash_set));
                }
                else return true;
                return result;
            };
            if (not dfs(source, {})) return false;
        }
        return true;
    }
};
