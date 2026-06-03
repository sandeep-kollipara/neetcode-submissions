#include <functional> 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        pair<bool,bool> row_to_zero = {false,false}; // first: current, second: previous
        int j=0;
        while (j<matrix.size()+1) { // raster scan (rows by columns)
            // scan the current row and previous row
            for (int i=0; i<matrix[0].size(); i++){
                // if current row has zero, mark the row for conversion to 0s
                if (j<matrix.size()) if (matrix[j][i]==0) row_to_zero.first=true;
                // if previous row has 0, make current 0
                if (j>0 and j<matrix.size()) if (matrix[j-1][i]==0) matrix[j][i]=0;
                // exception handling on last iteration, if last row has zero make column zero
                if (j==matrix.size()) if (matrix[j-1][i]==0) {
                    for (int k=0; k<matrix.size(); k++) matrix[k][i]=0;
                }
            }
            // if the previous row is marked, convert to zeroes;
            if (j>0 and row_to_zero.second==true) {
                transform(matrix[j-1].begin(), matrix[j-1].end(), matrix[j-1].begin(),
                    bind(multiplies<int>(), placeholders::_1, 0));
                //row_to_zero.second=false;
            }
            // reset variables
            row_to_zero.second = row_to_zero.first;
            row_to_zero.first = false;
            j++;
        }
    }
};
