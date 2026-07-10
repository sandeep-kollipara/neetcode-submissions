class Solution {
public:
    int arrangeCoins(int n) {
        int l=1, r=n, m=l+(r-l)/2;
        long sum_of_squares;
        while (l<=r) {
            sum_of_squares = (long)m*(m+1)/2;
            if (sum_of_squares > n) r=m-1;
            else if (sum_of_squares < n) l=m+1;
            else break;
            m = l+(r-l)/2;
        }
        sum_of_squares = (long)m*(m+1)/2;
        cout << m << endl;
        cout << sum_of_squares << endl;
        while (sum_of_squares <= n) { 
            m++;
            sum_of_squares = (long)m*(m+1)/2;
        }
        return m-1;
    }
};