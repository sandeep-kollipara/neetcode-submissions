class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> maxLocal(grid.size()-2, vector<int>(grid[0].size()-2, 0));
        auto conv=[&](int x, int y) {
            int maximum=INT_MIN;
            for (int i=x-1; i<=x+1; i++) {
                for (int j=y-1; j<=y+1; j++) {
                    maximum=max(maximum,grid[i][j]);
                }
            }
            return maximum;
        };
        for (int i=0; i<maxLocal.size(); i++) {
            for (int j=0; j<maxLocal[0].size(); j++) {
                maxLocal[i][j] = conv(i+1, j+1);
            }
        }
        return maxLocal;
    }
};