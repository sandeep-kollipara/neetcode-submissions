class NumMatrix {
private:
    vector<vector<int>> grid;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        grid = matrix;
        for (int i=1; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++) {
                grid[i][j] += grid[i-1][j];
            }
        }
        for (int i=0; i<grid.size(); i++){
            for (int j=1; j<grid[0].size(); j++) {
                grid[i][j] += grid[i][j-1];
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        /*int temp=row1;
        row1 = row2;
        row2 = temp;
        temp = col1;
        col1 = col2;
        col2 = temp;*/
        int big, small, top, left;
        big = grid[row2][col2];
        cout << big << endl;
        if (row1 > 0 and col1 > 0) small = grid[row1-1][col1-1];
        else small = 0;
        cout << small << endl;
        if (row1 > 0) top = grid[row1-1][col2];
        else top = 0;
        cout << top << endl;
        if (col1 > 0) left = grid[row2][col1-1];
        else left = 0;
        cout << left << endl;
        return big - top - left + small;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */