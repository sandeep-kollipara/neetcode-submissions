class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        auto hash_island=[&](pair<int,int> start){
            string s;
            queue<pair<int,int>> q;
            vector<pair<int,int>> points;
            int x_min=grid.size(), y_min=grid[0].size();
            q.push(start);
            while (!q.empty()) {
                pair<int,int> coord = q.front();
                points.push_back(coord);
                x_min = min(x_min, coord.first);
                y_min = min(y_min, coord.second);
                q.pop();
                // north
                if (coord.first>0 and grid[coord.first-1][coord.second]) {
                    q.push({coord.first-1,coord.second});
                    grid[coord.first-1][coord.second] = 0;
                }
                // east
                if (coord.second<grid[0].size()-1 and grid[coord.first][coord.second+1]) {
                    q.push({coord.first,coord.second+1});
                    grid[coord.first][coord.second+1] = 0;
                }
                // west
                if (coord.second>0 and grid[coord.first][coord.second-1]) {
                    q.push({coord.first,coord.second-1});
                    grid[coord.first][coord.second-1] = 0;
                }
                // south
                if (coord.first<grid.size()-1 and grid[coord.first+1][coord.second]) {
                    q.push({coord.first+1,coord.second});
                    grid[coord.first+1][coord.second] = 0;
                }
            }
            sort(points.begin(), points.end());
            for (auto& [a, b]: points) {
                s+=to_string(a-x_min);
                s+='_';
                s+=to_string(b-y_min);
                s+='__';
            }
            return s;
        };
        unordered_set<string> hashset;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]) hashset.insert(hash_island({i, j}));
            }
        }
        return hashset.size();
    }
};
