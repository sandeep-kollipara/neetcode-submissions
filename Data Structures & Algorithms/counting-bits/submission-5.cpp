class Solution {
public:
    vector<int> countBits(int n) {
        // define T[]= num of set bits in i
        vector<int> T(n+1, 0);
        // base case
        T[0] = 0;
        if (n>=1)T[1] = 1;
        // recurrence relation - T[i] = T[i-pow(2,int(log2(i)))]+1
        for (int i=2; i<=n; i++) {
            cout << i-pow(2,int(log2(i))) << " ";
            T[i] = T[i-pow(2,int(log2(i)))]+1;
        }
        return T;
    }
};
