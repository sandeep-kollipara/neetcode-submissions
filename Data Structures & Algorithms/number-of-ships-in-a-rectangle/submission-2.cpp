/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int ships=0;
        // Brute Force -  API call limit exceeded!
        /*for (int i=bottomLeft[0]; i<=topRight[0]; i++) {
            for (int j=bottomLeft[1]; j<topRight[1]; j++) {
                if (sea.hasShips({i,j},{i,j})) ships++;
            }
        }*/
        // Divide & Conquer
        auto d_and_c_2=[&](auto&& self, int y, int x_l, int x_r)->void {
            //cout << "d&c2: " << y << " : " << x_l << " , " << x_r << "." << endl;
            int m1=x_l+(x_r-x_l)/2, m2=m1+1;
            //cout << m1 << "," << m2;
            if (x_l<m1 and sea.hasShips({m1,y},{x_l,y})) self(self, y, x_l, m1);
            else if (x_l==m1 and sea.hasShips({m1,y},{x_l,y})) ships++;
            if (m2<x_r and sea.hasShips({x_r,y},{m2,y})) self(self, y, m2, x_r);
            else if (m2==x_r and sea.hasShips({x_r,y},{m2,y})) ships++;
        };
        auto d_and_c=[&](auto&& self, int y_l, int y_r)->void {
            //cout << "d&c: " << y_l << " , " << y_r << "." << endl;
            int m1=y_l+(y_r-y_l)/2, m2=m1+1;
            //cout << m1 << "," << m2;
            if (y_l<m1 and sea.hasShips({topRight[0],m1},{bottomLeft[0],y_l})) self(self, y_l, m1);
            else if (y_l==m1 and sea.hasShips({topRight[0],m1},{bottomLeft[0],y_l})) d_and_c_2(d_and_c_2, m1, bottomLeft[0], topRight[0]);
            if (m2<y_r and sea.hasShips({topRight[0],y_r},{bottomLeft[0],m2})) self(self, m2, y_r);
            else if (m2==y_r and sea.hasShips({topRight[0],y_r},{bottomLeft[0],m2})) d_and_c_2(d_and_c_2, m2, bottomLeft[0], topRight[0]);
        };
        d_and_c(d_and_c, bottomLeft[1], topRight[1]);
        return ships;
    }
};
