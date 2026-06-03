class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose
        for (int i=0; i<matrix[0].size(); i++) {
            for (int j=i; j<matrix.size(); j++) {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
        // flip
        for (int i=0; i<matrix[0].size()/2; i++) {
            for (int j=0; j<matrix.size(); j++) {
                int temp = matrix[j][i];
                matrix[j][i] = matrix[j][matrix[0].size()-i-1];
                matrix[j][matrix[0].size()-i-1] = temp;
            }
        }
    }
};
