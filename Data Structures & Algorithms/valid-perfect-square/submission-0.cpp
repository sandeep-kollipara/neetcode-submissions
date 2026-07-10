class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=0, r=num, m=l+(r-l)/2;
        long square;
        while (l<=r) {
            square = (long)m*m;
            if (square > num) r=m-1;
            else if (square < num) l=m+1;
            else return true;
            m = l+(r-l)/2;
        }
        return false;
    }
};