class Solution {
public:
    int climbStairs(int n) {
        //int T[n+1];
        vector<int> T(n+1);
        // base case
        T[0] = 0;
        T[1] = 1;
        T[2] = 2;
        // recurrence relation
        if (n > 2) for(int i=3; i<n+1; i++) T[i] = T[i-1] + T[i-2];
        for (int i: T) cout << i << " ";
        cout << endl;
        return T[n];
    }
};
