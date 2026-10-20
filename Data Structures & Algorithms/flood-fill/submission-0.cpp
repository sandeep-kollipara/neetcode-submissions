class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc]==color) return image; // edge case 
        auto dfs=[&](auto&& self, int r, int c, int original, int neuva){
            // base case or termination
            if (image[r][c]!=original) return ;
            // processing
            image[r][c] = neuva;
            // traversal
            if (r-1>-1) { // up
                self(self, r-1, c, original, neuva);
            } if (r+1<image.size()) { // down
                self(self, r+1, c, original, neuva);
            } if (c-1>-1) { // left
                self(self, r, c-1, original, neuva);
            } if (c+1<image[0].size()) { // right
                self(self, r, c+1, original, neuva);
            }
            return ;
        };
        dfs(dfs, sr, sc, image[sr][sc], color);
        return image;
    }
};