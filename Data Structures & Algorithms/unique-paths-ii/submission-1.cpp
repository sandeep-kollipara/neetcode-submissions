class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]==1) return 0;
        // define T[i][j] = num of ways to reach the indexed position on grid
        vector<vector<int>> T(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        // base case
        T[0][0] = 1;
        for (int i=1; i<obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0]==1) T[i][0] = 0;
            else T[i][0] = T[i-1][0];
        }
        for (int j=1; j<obstacleGrid[0].size(); j++) {
            if (obstacleGrid[0][j]==1) T[0][j] = 0;
            else T[0][j] = T[0][j-1];
        }
        // recurrence relation - T[i][j] = T[i-1][j] + T[i][j-1]
        if (obstacleGrid.size()>1
        and obstacleGrid[0].size()>1) for (int j=1; j<obstacleGrid[0].size(); j++) {
            for (int i=1; i<obstacleGrid.size(); i++) {
                if (obstacleGrid[i][j]==1) T[i][j] = 0;
                else T[i][j] = T[i-1][j] + T[i][j-1];
            }
        }
        return T[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};