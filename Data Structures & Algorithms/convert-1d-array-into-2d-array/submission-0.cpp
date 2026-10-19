class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m*n!=original.size()) return {};
        vector<vector<int>> arr2d(m,vector<int>(n,0));
        int x, y;
        for (int i=0; i<original.size(); i++) {
            x=i/n;
            y=i%n;
            arr2d[x][y]=original[i];
        }
        return arr2d;
    }
};
