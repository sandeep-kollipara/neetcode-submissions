class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        struct hash_pair{
            inline size_t operator()(const pair<int,int>& v) const {
                return 31*v.first + v.second;
            }
        };
        unordered_set<pair<int,int>, hash_pair> vertices;
        vector<pair<int, int>> rotten;
        for (int i=0; i<grid[0].size(); i++) {
            for (int j=0; j<grid.size(); j++) {
                if (grid[j][i]==1) vertices.insert(pair<int, int>({i, j})); // sink
                if (grid[j][i]==2) rotten.push_back(pair<int, int>({i, j})); // source
            }
        }
        cout << vertices.size() << endl;
        int time=0;
        while(!vertices.size()==0) {
            vector<pair<int,int>> rotting;
            for (pair<int,int> rot: rotten) {
                int x = rot.first, y = rot.second;
                if (vertices.find(pair<int,int>({x,y-1}))!=vertices.end() 
                and grid[y-1][x]==1) { // north
                    grid[y-1][x]==2;
                    vertices.erase(pair<int,int>({x,y-1}));
                    rotting.push_back(pair<int,int>({x,y-1}));
                }
                if (vertices.find(pair<int,int>({x+1,y}))!=vertices.end() 
                and grid[y][x+1]==1) { // east
                    grid[y][x+1]==2;
                    vertices.erase(pair<int,int>({x+1,y}));
                    rotting.push_back(pair<int,int>({x+1,y}));
                }
                if (vertices.find(pair<int,int>({x-1,y}))!=vertices.end() 
                and grid[y][x-1]==1) { // west
                    grid[y][x-1]==2;
                    vertices.erase(pair<int,int>({x-1,y}));
                    rotting.push_back(pair<int,int>({x-1,y}));
                }
                if (vertices.find(pair<int,int>({x,y+1}))!=vertices.end() 
                and grid[y+1][x]==1) { // south
                    grid[y+1][x]==2;
                    vertices.erase(pair<int,int>({x,y+1}));
                    rotting.push_back(pair<int,int>({x,y+1}));
                }
            }
            if (rotting.size()==0) break; // termination
            //rotten.insert(rotten.end(), rotting.begin(), rotting.end());
            rotten = rotting;
            time++;
        }
        if (vertices.size()) return -1;
        else return time;
    }
};
