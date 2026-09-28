class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> box(2, vector<int>(rowIndex+1, 0));
        box[0][0] = 1;
        for (int i=1; i<rowIndex+1; i++) {
            int x = i%2, y = 1-x;
            box[x][0] = box[x][i] = 1;
            for (int j=1; j<=i-1; j++) {
                box[x][j] = box[y][j-1] +box[y][j];
            }
        }
        return box[rowIndex%2];
    }
};