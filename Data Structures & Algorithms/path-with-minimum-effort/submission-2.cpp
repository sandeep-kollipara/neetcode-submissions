class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<bool>> visited = vector<vector<bool>>(heights.size(), 
            vector<bool>(heights[0].size(), false));
        typedef pair<int,pair<int,int>> token;
        auto cmp=[](token a, token b) { // min heap
            return a.first > b.first;
        };
        priority_queue<token, vector<token>, decltype(cmp)> pq(cmp);
        // initialization
        int r=0, c=0, max_effort=0;
        while (!(r==heights.size()-1 and c==heights[0].size()-1)) { // termination
            // processing
            visited[r][c] = true;
            // proliferation
            int inf = 1e9;
            int north=inf, east=inf, west=inf, south=inf; 
            if (r-1>-1 and !visited[r-1][c]) { // north
                north = abs(heights[r-1][c] - heights[r][c]);
                token north_token = {north, {r-1, c}};
                pq.push(north_token);
            } if (c+1<heights[0].size() and !visited[r][c+1]) { // east
                east = abs(heights[r][c+1] - heights[r][c]);
                token east_token = {east, {r, c+1}};
                pq.push(east_token);
            } if (c-1>-1 and !visited[r][c-1]) { // west
                west = abs(heights[r][c-1] - heights[r][c]);
                token west_token = {west, {r, c-1}};
                pq.push(west_token);
            } if (r+1<heights.size() and !visited[r+1][c]) { // south
                south = abs(heights[r+1][c] - heights[r][c]);
                token south_token = {south, {r+1, c}};
                pq.push(south_token);
            }
            //cout << r << "," << c << ": " << pq.size() << endl;
            //if (pq.empty()) break;
            token next_token = pq.top();
            pq.pop();
            r = next_token.second.first;
            c = next_token.second.second;
            max_effort = max(max_effort, next_token.first);
        }
        return max_effort;
    }
};