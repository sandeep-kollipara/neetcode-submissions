class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int diag=0, alter=0;
        for (int i=0; i<mat.size(); i++) {
            diag+=mat[i][i];
            alter+=mat[i][mat.size()-i-1];
        }
        if (mat.size()%2) alter-=mat[mat.size()/2][mat.size()/2];
        return diag+alter;
    }
};