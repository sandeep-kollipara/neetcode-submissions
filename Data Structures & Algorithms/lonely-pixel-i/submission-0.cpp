class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        // O(n^2) is unavoidable
        vector<int> row(picture[0].size(), 0), col(picture.size(), 0);
        for (int i=0; i<picture.size(); i++) {
            for (int j=0; j<picture[0].size(); j++) {
                if (picture[i][j]=='B') {
                    col[i]++;
                    row[j]++;
                }
            }
        }
        int lonely_pixel=0;
        for (int i=0; i<picture.size(); i++) {
            for (int j=0; j<picture[0].size(); j++) {
                if (picture[i][j]=='B' and col[i]==1 and row[j]==1) {
                    lonely_pixel++;
                }
            }
        }
        return lonely_pixel;
    }
};
