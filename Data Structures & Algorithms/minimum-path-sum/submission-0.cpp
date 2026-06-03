class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // define T[i][j] = least sum path to reach the grid index
        vector<vector<int>> T(grid.size(), vector<int>(grid[0].size(), -1));
        // base case
        T[0][0] = grid[0][0];
        for (int i=1; i<grid.size(); i++) {
            T[i][0] = T[i-1][0] + grid[i][0];
        }
        for (int j=1; j<grid[0].size(); j++) {
            T[0][j] = T[0][j-1] + grid[0][j];
        }
        // recurrence relation - T[i][j] = min(T[i-1][j], T[i][j-1]) + grid[i][j]
        if (grid.size()>1
        and grid[0].size()>1) for (int i=1; i<grid.size(); i++) {
            for (int j=1; j<grid[0].size(); j++) {
                T[i][j] = min(T[i-1][j], T[i][j-1]) + grid[i][j];
            }
        }
        return T[grid.size()-1][grid[0].size()-1];
    }
};