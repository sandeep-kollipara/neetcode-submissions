class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int u=grid.size(), v=grid[0].size();
        vector<vector<int>> shift(u, vector<int>(v));
        for (int i=0; i<u; i++) {
            for (int j=0; j<v; j++) {
                int x=(i*v+j+k)/v, y=(i*v+j+k)%v;
                x=x%u;
                shift[x][y] = grid[i][j];
            }
        }
        return shift;
    }
};
