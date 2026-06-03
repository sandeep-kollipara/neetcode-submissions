class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> initial_courses;
        for (int i=0; i<numCourses; i++) initial_courses.push_back(i); 
        function<vector<int>(vector<int>, vector<vector<int>>)> findOrderDAG=[&](vector<int> courses, vector<vector<int>> nums){
            // normal directed graph and reverse directed graph
            unordered_map<int, vector<int>> hash_table;
            unordered_map<int, vector<int>> reverse_hash_table;
            vector<int> sources, sinks;
            for (vector<int> vec: nums) {
                int source = vec[1], sink = vec[0];
                if (hash_table.find(source)==hash_table.end()) hash_table[source]={sink};
                else hash_table[source].push_back(sink);
                sources.push_back(source);
                if (reverse_hash_table.find(sink)==reverse_hash_table.end()) reverse_hash_table[sink]={source};
                else reverse_hash_table[sink].push_back(source);
                sinks.push_back(sink);
            }
            // find the farthest sink in the normal graph
            int farthest_sink, max_depth_global=0;
            vector<int> sources_copy = sources;
            while(!sources_copy.empty()) {
                int source = sources_copy[0], max_depth=0, far_sink;
                sources_copy.erase(sources_copy.begin());
                function<bool(int,unordered_set<int>)> dfs_1=[&](int i, unordered_set<int> hash_set) {
                    bool result=true;
                    // cycle detection
                    if (hash_set.find(i)==hash_set.end()) hash_set.insert(i);
                    else return false;
                    // update depth
                    if (max_depth<hash_set.size()) max_depth=hash_set.size();
                    // termination
                    if (hash_table.find(i)==hash_table.end()) {
                        if (max_depth==hash_set.size()) far_sink = i; //farthest sink
                        return true;
                    }
                    // proliferation
                    else{
                        for (int j: hash_table[i]) result = (result and dfs_1(j, hash_set));
                    }
                    return result;
                };
                if (dfs_1(source, {})==false) return vector<int>({}); // cycle found, end program
                else {
                    if (max_depth > max_depth_global) {
                        max_depth_global = max_depth;
                        farthest_sink = far_sink;
                    }
                }
            }
            // find the farthest source in reverse graph using the farthest sink in normal graph
            int max_depth=0, far_source;
            /*unordered_set*/vector<int> dag_longest_path;
            function<void(int,/*unordered_set*/vector<int>)> dfs_2=[&](int i, /*unordered_set*/vector<int> /*hash_set*/vec) {
                // path update
                /*if (hash_set.find(i)==hash_set.end()) hash_set.insert(i);*/
                if (find(vec.begin(), vec.end(), i)==vec.end()) vec.push_back(i);
                // update depth
                if (max_depth</*hash_set*/vec.size()) max_depth=/*hash_set*/vec.size();
                // termination
                if (reverse_hash_table.find(i)==reverse_hash_table.end()) {
                    if (max_depth==/*hash_set*/vec.size()) {
                        far_source = i; //farthest sink
                        dag_longest_path = /*hash_set*/vec;
                    }
                }
                // proliferation
                else{
                    for (int j: reverse_hash_table[i]) dfs_2(j, /*hash_set*/vec);
                }
            };
            dfs_2(farthest_sink, {}); // gives far_source and dag_longest_path
            reverse(dag_longest_path.begin(), dag_longest_path.end()); // so as to align it with normal graph
            cout << "Dag longest path:";
            for (int i=0; i<dag_longest_path.size(); i++) cout << dag_longest_path[i] << " ";
            cout << endl;
            // qa longest path
            /*for (int i: dag_longest_path) cout << i << " ";
            cout << endl;
            return vector<int>({1,2,3});*/
            // calculating sources not in dag_longest_path and finding the previous tracks
            vector<int> sources_2=sources;
            /*unordered_set*/vector<int> visited=dag_longest_path, previous_path;
            for (int i: dag_longest_path) sources_2.erase(remove(sources_2.begin(), sources_2.end(), i), sources_2.end());
            cout << "sources_2: ";
            for (int i=0; i<sources_2.size(); i++) cout << sources_2[i] << " ";
            cout << endl;
            while(!sources_2.empty()) {
                vector<int> previous={};
                int source = sources_2[0];
                sources_2.erase(sources_2.begin());
                function<void(int,/*unordered_set*/vector<int>)> dfs_3=[&](int i, /*unordered_set*/vector<int> /*hash_set*/vec) {
                    // path update
                    /*if (hash_set.find(i)==hash_set.end()) hash_set.insert(i);*/
                    if (find(vec.begin(), vec.end(), i)==vec.end()) vec.push_back(i);
                    // termination
                    /*if (visited.find(i)!=visited.end()) {*/
                    if (find(visited.begin(), visited.end(), i)!=visited.end()) {
                        for (int i: /*hash_set*/vec) {
                            /*visited.insert(i);*/visited.push_back(i);
                            /*previous.insert(i);*/previous.push_back(i);
                        }
                        previous.pop_back(); // remove last element which is already visited
                        return ;
                    }
                    else if (hash_table.find(i)==hash_table.end()) {
                        return ;
                    }
                    // proliferation
                    else{
                        for (int j: hash_table[i]) dfs_3(j, /*hash_set*/vec);
                    }
                };
                dfs_3(source, {});
                // attach the newly discovered portion at the beginning to preserve order
                previous_path.insert(previous_path.begin(), previous.begin(), previous.end());
            }
            cout << "Previous path:";
            for (int i=0; i<previous_path.size(); i++) cout << previous_path[i] << " ";
            cout << endl;
            // calculating sinks not in dag_longest_path and finding the previous tracks
            vector<int> sinks_2=sinks;
            visited=dag_longest_path; // resetting this so as to account for acyclic loops
            /*unordered_set*/vector<int> next_path;
            for (int i: visited) sinks_2.erase(remove(sinks_2.begin(), sinks_2.end(), i), sinks_2.end());
            cout << "sinks_2: ";
            for (int i=0; i<sinks_2.size(); i++) cout << sinks_2[i] << " ";
            cout << endl;
            while(!sinks_2.empty()) {
                vector<int> next={};
                int sink = sinks_2[0];
                sinks_2.erase(sinks_2.begin());
                function<void(int,/*unordered_set*/vector<int>)> dfs_4=[&](int i, /*unordered_set*/vector<int> /*hash_set*/vec) {
                    // path update
                    //if (hash_set.find(i)==hash_set.end()) hash_set.insert(i);
                    if (find(vec.begin(), vec.end(), i)==vec.end()) vec.push_back(i);
                    // termination
                    /*if (visited.find(i)!=visited.end()) {*/
                    if (find(visited.begin(), visited.end(), i)!=visited.end()) {
                        for (int i: /*hash_set*/vec) {
                            /*visited.insert(i);*/visited.push_back(i);
                            /*next.insert(i);*/next.push_back(i);
                        }
                        next.pop_back(); // remove last element which is already visited
                        return ;
                    }
                    else if (reverse_hash_table.find(i)==reverse_hash_table.end()) {
                        return ; // not possible
                    }
                    // proliferation
                    else{
                        for (int j: reverse_hash_table[i]) dfs_4(j, /*hash_set*/vec);
                    }
                };
                dfs_4(sink, {});
                // attach the newly discovered portion at the beginning to preserve order
                next_path.insert(next_path.begin(), next.begin(), next.end());
            }
            reverse(next_path.begin(), next_path.end()); // so as to align it with dag_longest_path
            cout << "Next path:";
            for (int i=0; i<next_path.size(); i++) cout << next_path[i] << " ";
            cout << endl;
            // finding common elements in previous_path and next_path
            vector<int> pre = previous_path, nex = next_path, common;
            sort(pre.begin(), pre.end());
            sort(nex.begin(), nex.end());
            set_intersection(pre.begin(), pre.end(),nex.begin(), nex.end(), back_inserter(common));
            for (int i: common) previous_path.erase(remove(previous_path.begin(),previous_path.end(),i),previous_path.end());
            for (int i: common) next_path.erase(remove(next_path.begin(),next_path.end(),i),next_path.end());
            // final result = previous + dag_longest_path + next
            vector<int> result=previous_path;
            /*for (int i: previous_path) result.push_back(i);
            for (int i: dag_longest_path) result.push_back(i);
            for (int i: next_path) result.push_back(i);*/
            result.insert(result.end(), dag_longest_path.begin(), dag_longest_path.end());
            result.insert(result.end(), next_path.begin(), next_path.end());
            /*for (int i=0; i<numCourses; i++) if (visited.find(i)==visited.end()) result.push_back(i);*/
            while(!common.empty()) {
                int i = common[0];
                common.erase(common.begin());
                vector<int> prerequisite=reverse_hash_table[i], indices;
                for (int j: prerequisite) {
                    for (int k=result.size()-1; k>-1; k--) {
                        if (result[k]==j) indices.push_back(k);
                    }
                }
                if (indices.size()==0) {
                    common.push_back(i);
                    continue;
                }
                else {
                    result.insert(result.begin()+*max_element(indices.begin(),indices.end())+1,i);
                }
            }
            for (int i=1; i<result.size(); i++) if (result[i-1]==result[i]) result.erase(result.begin()+i);
            /*for (int i=0; i<numCourses; i++) if (find(visited.begin(), visited.end(), i)==visited.end()) result.push_back(i);*/
            unordered_set<int> disconnected;
            vector<vector<int>> next_nums;
            //for (int i=0; i<numCourses; i++) if (find(result.begin(), result.end(), i)==result.end()) disconnected.insert(i);
            for (int i: courses) if (find(result.begin(), result.end(), i)==result.end()) disconnected.insert(i);
            for (vector<int> entry: nums) {
                if (disconnected.find(entry[0])!=disconnected.end() 
                and disconnected.find(entry[1])!=disconnected.end()) next_nums.push_back(entry);
            }
            vector<int> next_courses;
            for (int i: disconnected) next_courses.push_back(i);
            vector<int> next_loop;
            if (disconnected.size()!=0 and next_nums.size()!=0) next_loop = findOrderDAG(next_courses, next_nums);
            else if (next_nums.size()==0) for (int i: disconnected) result.push_back(i);
            result.insert(result.end(), next_loop.begin(), next_loop.end()); 
            return result;
        };
        return findOrderDAG(initial_courses, prerequisites);
        // (done) need fix: preserve order in the dfs_2, dfs_3 and dfs_4
        // (done) need fix: remove duplicates from multi traversals
        // (done) need fix: account for acyclic loops (repeats in previous_path and next_path)
        // (done) found error: source and sink are reversed
        // (done) need fix: previous_path and next_path have non-common elements
        // (n/a) need fix: ordering of result creation
        // need fix: doesn't account for disconnected node networks from longest dag
    }
};
