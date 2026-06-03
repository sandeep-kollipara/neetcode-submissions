class Solution {
public:
    int tribonacci(int n) {
        // define T[i] = ith tribonacci seq number
        vector<int> T(n+1);
        // base case
        T[0] = 0;
        T[1] = 1;
        T[2] = 1;
        // recurrence relation - T[i] = T[i-1] + T[i-2] + T[i-3]
        if (n > 2) for (int i=3; i<n+1; i++) {
            T[i] = T[i-1] + T[i-2] + T[i-3];
        }
        return T[n];
    }
};