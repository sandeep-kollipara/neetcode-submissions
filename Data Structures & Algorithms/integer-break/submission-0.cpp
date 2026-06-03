class Solution {
public:
    int integerBreak(int n) {
        // define T[i] = max product of 2+ positive integers adding up to i
        vector<int> T(n+1);
        // base - not valid for solution
        T[0] = 0;
        T[1] = 1; // should be 0
        T[2] = 2; // should be 1
        T[3] = 3; // should be 2
        T[4] = 4;
        // recurrence relation - T[i] = j=1->i/2+1 MAX(T[j]*T[i-j])
        if (n>4) for (int i=5; i<n+1; i++) {
            int j=1, j_max=i/2+1, t=1;
            for (j=1; j<=j_max; j++) {
                t = max(t, T[j]*T[i-j]);
            }
            T[i] = t;
            cout << i << " : " << t << endl;
        }
        if (n < 4) return n-1; // exception
        return T[n];
    }
};