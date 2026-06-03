class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) { // changed char to int in grid
        struct pair_hash {
            inline std::size_t operator()(const std::pair<int,int> & v) const {
                return v.first*31+v.second;
            }
        };
        unordered_set<pair<int,int>, pair_hash> vertices;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                vertices.insert(pair<int,int>({j,i}));
            }
        }
        //int num_islands = 0;
        vector<int> areas;
        while (!vertices.empty()){
            int area;
            pair<int,int> vertex;
            // find an island vertex and erase any sea vertices you find
            vector<pair<int,int>> sea={};
            for (pair<int,int> v: vertices) {
                vertex = v;
                if (grid[v.second][v.first] == 1) break;
                else sea.push_back(v);
            }
            for (pair<int,int> water: sea) vertices.erase(water);
            // eliminate all land nearby
            function<void(int, int)> land_search_and_delete=[&](int x, int y) {
                area++;
                vertices.erase(pair<int,int>({x,y}));
                if (vertices.find(pair<int,int>({x,y+1}))!=vertices.end()
                and grid[y+1][x]==1) { // north
                    land_search_and_delete(x, y+1);
                }
                if (vertices.find(pair<int,int>({x+1,y}))!=vertices.end()
                and grid[y][x+1]==1) { // east
                    land_search_and_delete(x+1, y);
                }
                if (vertices.find(pair<int,int>({x-1,y}))!=vertices.end()
                and grid[y][x-1]==1) { // west
                    land_search_and_delete(x-1, y);
                }
                if (vertices.find(pair<int,int>({x,y-1}))!=vertices.end()
                and grid[y-1][x]==1) { // south
                    land_search_and_delete(x, y-1);
                }
            };
            area=0;
            if (!vertices.empty()) {
                int j = vertex.second, i = vertex.first;
                land_search_and_delete(i, j);
                //num_islands++;
            }
            areas.push_back(area);
        }
        //return num_islands;
        return *max_element(areas.begin(), areas.end());
    }
};
