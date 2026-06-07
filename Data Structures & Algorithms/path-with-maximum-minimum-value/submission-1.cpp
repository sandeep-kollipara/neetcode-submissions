class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        typedef struct{
            int first;
            int second;
            int third;
        }trio;
        auto comp=[](trio a, trio b) { // max heap
            return a.first < b.first;
        };
        priority_queue<trio, vector<trio>, decltype(comp)> pq(comp);
        vector<vector<bool>> hist(grid.size(), vector<bool>(grid[0].size(), false));
        pair<int, int> loc = make_pair(grid.size()-1, grid[0].size()-1);
        //cout << loc.first << ", " << loc.second << endl;    
        hist[loc.first][loc.second] = true;
        int score = grid[loc.first][loc.second];//INT_MAX;
        while (loc!=make_pair(0,0)) {
            // north
            if (loc.first>0 and !hist[loc.first-1][loc.second]) {
                pair<int,int> north = make_pair(loc.first-1, loc.second);
                trio up = {grid[north.first][north.second], north.first, north.second};
                pq.push(up);
                hist[loc.first-1][loc.second]=true;
            }
            // east
            if (loc.second<grid[0].size()-1 and !hist[loc.first][loc.second+1]) {
                pair<int,int> east = make_pair(loc.first, loc.second+1);
                trio right = {grid[east.first][east.second], east.first, east.second};
                pq.push(right);
                hist[loc.first][loc.second+1]=true;
            }
            // west
            if (loc.second>0 and !hist[loc.first][loc.second-1]) {
                pair<int,int> west = make_pair(loc.first, loc.second-1);
                trio left = {grid[west.first][west.second], west.first, west.second};
                pq.push(left);
                hist[loc.first][loc.second-1]=true;
            }
            // south
            if (loc.first<grid.size()-1 and !hist[loc.first+1][loc.second]) {
                pair<int,int> south = make_pair(loc.first+1, loc.second);
                trio down = {grid[south.first][south.second], south.first, south.second};
                pq.push(down);
                hist[loc.first+1][loc.second]=true;
            }
            // advance
            if (pq.size()==0) break;
            if (score > pq.top().first) score = pq.top().first;
            loc = make_pair(pq.top().second, pq.top().third);
            //cout << pq.size() << " " << pq.top().first << " : " << loc.first << ", " << loc.second << endl;
            pq.pop();
        }
        return score;
    }
};
