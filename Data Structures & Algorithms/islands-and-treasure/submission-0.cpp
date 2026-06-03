class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        struct hash_pair{
            inline size_t operator()(const pair<int,int> &v) const {
                return v.first*31 + v.second;
            }
        };
        unordered_set<pair<int,int>, hash_pair> vertices;
        // insert all tractable nodes i.e., non-sea nodes
        vector<pair<int,int>> treasures;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]!=-1) vertices.insert(pair<int,int>({j,i}));
                if (grid[i][j]==0) treasures.push_back(pair<int,int>({j,i}));
            }
        }
        cout << vertices.size() << endl;
        cout << treasures.size() << endl;
        cout << treasures[0].first << "," << treasures[0].second << endl;
        for (pair<int,int> start: treasures) {
            queue<pair<int,int>> q;
            q.push(start);
            pair<int,int> coords;
            //int distance=0; // incorrect
            // start from treasure and do a bfs search on vertices until exhaustion
            while (!q.empty()){
                coords = q.front();
                q.pop();
                int x = coords.first, y = coords.second;
                // processing
                //grid[y][x] = distance;
                //distance++;
                //cout << distance << endl;
                cout << (vertices.find(pair<int,int>({x,y-1}))!=vertices.end()) 
                << (vertices.find(pair<int,int>({x+1,y}))!=vertices.end()) 
                << (vertices.find(pair<int,int>({x-1,y}))!=vertices.end()) 
                << (vertices.find(pair<int,int>({x,y+1}))!=vertices.end()) << endl;
                // proliferation
                if (vertices.find(pair<int,int>({x,y-1}))!=vertices.end() 
                and grid[y-1][x]>grid[y][x] + 1) { // north
                    q.push(pair<int,int>({x,y-1}));
                    grid[y-1][x] = grid[y][x] + 1;
                }
                if (vertices.find(pair<int,int>({x+1,y}))!=vertices.end() 
                and grid[y][x+1]>grid[y][x] + 1) { //east
                    q.push(pair<int,int>({x+1,y}));
                    grid[y][x+1] = grid[y][x] + 1;
                }
                if (vertices.find(pair<int,int>({x-1,y}))!=vertices.end() 
                and grid[y][x-1]>grid[y][x] + 1){ // west
                     q.push(pair<int,int>({x-1,y}));
                     grid[y][x-1] = grid[y][x] + 1;
                }
                if (vertices.find(pair<int,int>({x,y+1}))!=vertices.end() 
                and grid[y+1][x]>grid[y][x] + 1){ // south
                     q.push(pair<int,int>({x,y+1}));
                     grid[y+1][x] = grid[y][x] + 1;
                }
            }
        }
    }
};
