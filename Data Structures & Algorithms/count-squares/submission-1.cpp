class CountSquares {
private:
vector<vector<int>> grid = vector<vector<int>>(1001, vector<int>(1001, 0));

public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        grid[point[0]][point[1]] += 1;
    }
    
    int count(vector<int> point) {
        int squares=0;
        for (int i=0; i<grid.size(); i++) {
            // first, collect all the points sharing the abscissa
            if (i!=point[0] and grid[i][point[1]]>0) {
                // second, check if corresponding point(s) exists 
                // that shares the ordinate in both directions
                int j1=point[1]-(i-point[0]), j2=point[1]+(i-point[0]);
                if (j1>-1 and j1<1001 and grid[point[0]][j1]>0) {
                    // third, confirm if the fourth point exists
                    if (grid[i][j1]>0) {
                        // collate the possible squares
                        squares+=((/*grid[point[0]][point[1]]+*/1)*grid[i][point[1]]*grid[i][j1]*grid[point[0]][j1]);
                    }
                } if (j2>-1 and j2<1001 and grid[point[0]][j2]>0) {
                    // third, confirm if the fourth point exists
                    if (grid[i][j2]>0) {
                        // collate the possible squares
                        squares+=((/*grid[point[0]][point[1]]+*/1)*grid[i][point[1]]*grid[i][j2]*grid[point[0]][j2]);
                    }
                }
            }
        }
        return squares;
    }
};
