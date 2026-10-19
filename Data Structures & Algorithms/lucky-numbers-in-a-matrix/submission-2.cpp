class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> lucky;
        vector<pair<int,int>> prospects;
        for (int i=0; i<matrix.size(); i++) {
            int minimum=INT_MAX;
            for (int j=0; j<matrix[0].size(); j++) {
                minimum = min(minimum,matrix[i][j]);
            }
            int pos=-1;
            for (int j=0; j<matrix[0].size(); j++) {
                if (minimum==matrix[i][j]) pos=j;
            }
            prospects.push_back({i,pos});
        }
        for (pair<int,int> j: prospects) {
            int maximum=INT_MIN;
            for (int i=0; i<matrix.size(); i++) {
                maximum = max(maximum, matrix[i][j.second]);
            }
            int pos=-1;
            for (int i=0; i<matrix.size(); i++) {
                if (maximum==matrix[i][j.second]) pos=i;
            }
            if (pos==j.first) lucky.push_back(matrix[j.first][j.second]);
        }
        return lucky;
    }
};
