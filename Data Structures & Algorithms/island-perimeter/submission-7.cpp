class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        struct pair_hash{
            size_t operator()(const pair<int,int> &x) const{
                return 32*x.first + x.second;
            }
        };
        unordered_set<pair<int,int>, pair_hash> hash_set;
        int perimeter=0;
        function<void(pair<int,int>)> dfs=[&](pair<int,int> coord){
            // revisited
            if (hash_set.find(coord)!=hash_set.end()) return;
            // escape sea
            if (grid[coord.first][coord.second]==0 
            and coord.second!=grid[0].size()-1) {
                dfs(pair<int,int>({coord.first, coord.second+1}));
                return;
            }
            else if (grid[coord.first][coord.second]==0 
            and coord.second==grid[0].size()-1) {
                dfs(pair<int,int>({coord.first+1, 0}));
                return;
            }
            // scout the land
            //int local=0;
            hash_set.insert(coord);
            if (coord.first-1==-1
            or grid[coord.first-1][coord.second]==0) { // north
                perimeter++;
                //local++;
            }
            else dfs(pair<int,int>({coord.first-1, coord.second}));
            if (coord.second+1==grid[0].size() 
            or grid[coord.first][coord.second+1]==0) { // east
                perimeter++;
                //local++;
            }
            else dfs(pair<int,int>({coord.first, coord.second+1}));
            if (coord.second-1==-1 
            or grid[coord.first][coord.second-1]==0) { // west
                perimeter++;
                //local++;
            }
            else dfs(pair<int,int>({coord.first, coord.second-1}));
            if (coord.first+1==grid.size() 
            or grid[coord.first+1][coord.second]==0) { // south
                perimeter++;
                //local++;
            }
            else dfs(pair<int,int>({coord.first+1, coord.second}));
            //cout << "pair (" << coord.first << "," << coord.second << ") - " << local << endl;
        };
        dfs(pair<int,int>({0,0}));
        return perimeter;
    }
};