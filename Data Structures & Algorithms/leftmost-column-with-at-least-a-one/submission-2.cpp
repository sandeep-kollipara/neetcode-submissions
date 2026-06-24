/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int least_col=INT_MAX;
        for (int i=0; i<dim[0]; i++) {
            int l=0, r=dim[1]-1, m=l+(r-l)/2;
            while (l<=r) {
                if (binaryMatrix.get(i,m)) r=m-1;
                else l=m+1;
                m=l+(r-l)/2;
            }
            //while (m>0 and !binaryMatrix.get(i,m)) m--;
            //m++;
            //cout << m << endl;
            least_col = min(m, least_col);
        }
        if (least_col < dim[1])return least_col;
        else return -1;
    }
};
