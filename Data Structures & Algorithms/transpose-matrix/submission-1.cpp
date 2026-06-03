class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        if (m!=n) {
            vector<vector<int>> transpose(n, vector<int>(m));
            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++) {
                    transpose[j][i] = matrix[i][j];
                }
            }
            return transpose;
        }
        else {
            for (int i=0; i<m; i++) {
                for (int j=0; j<i; j++) {
                    int temp = matrix[j][i];
                    matrix[j][i] = matrix[i][j];
                    matrix[i][j] = temp;
                }
            }
            return matrix;
        }
    }
};