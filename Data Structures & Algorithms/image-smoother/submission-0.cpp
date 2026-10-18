class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        auto conv=[&](int row, int col){
            int sum=0, den=0;
            /*int sum=img[row][col], den=1;
            if (row>0) { // up
                sum+=img[row-1][col];
                den++;
            }
            if (row<img.size()-1) { // down
                sum+=img[row+1][col];
                den++;
            }
            if (col>0) { // left
                sum+=img[row][col-1];
                den++;
            }
            if (col<img[0].size()-1) { // right
                sum+=img[row][col+1];
                den++;
            }*/
            for (int i=-1; i<2; i++) {
                for (int j=-1; j<2; j++) {
                    int x=row+i, y=col+j;
                    if (x>-1 and x<img.size() 
                    and y>-1 and y<img[0].size()) {
                        sum+=img[x][y];
                        den++;
                    }
                }
            }
            return sum/den;
        };
        vector<vector<int>> res(img);
        for (int i=0; i<img.size(); i++) {
            for (int j=0; j<img[0].size(); j++) {
                res[i][j] = conv(i, j);
            }
        }
        return res;
    }
};
