class Solution {
public:
    int numSquares(int n) {
        // define T[i] = least num of perfect squares' summation to i
        vector<int> T(n+1);
        // base case
        T[0] = 0; // 0^2
        // recurrence relation - T[i] = j=1->sqrt(i) MIN (1+T[i-j^2])
        if (n>0) for (int i=1; i<n+1; i++) {
            int j_max = sqrt(i), j=1, t=1e9;
            for (j=1; j<=j_max; j++) {
                t=min(t, 1+T[i-j*j]);
            }
            T[i] = t;
        }
        return T[n];
    }
};