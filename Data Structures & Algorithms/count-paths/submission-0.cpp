class Solution {
public:
    int uniquePaths(int m, int n) {
        // define T[i][j] = num of unique paths reaching the cell
        vector<vector<int>> T(m, vector<int>(n));
        // base case
        for (int i=0; i<m; i++) T[i][0]=1;
        for (int j=0; j<n; j++) T[0][j]=1;
        // recurrence relation - T[i][j] = T[i][j-1] + T[i-1][j] for i>1, j>1
        if (m>0 and n>0) for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                T[i][j] = T[i-1][j] + T[i][j-1];
            }
        }
        return T[m-1][n-1];
    }
};
