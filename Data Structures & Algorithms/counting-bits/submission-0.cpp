class Solution {
public:
    vector<int> countBits(int n) {
        // define T[i] = num of 1 bits in binary rep of i
        vector<int> T(n+1);
        // base case
        T[0] = 0;
        if (n==0) return T;
        T[1] = 1;
        if (n==1) return T;
        int cycles = log2(n)+1;
        if (n>1) for (int i=2; i<pow(2,cycles); i++) {
            // recurrence relation - T[i] = 1 + T[i-2^int(log2(i))]
            T[i] = 1 + T[i-pow(2,int(log2(i)))];
            // termination
            if (n==i) break;
        }
        return T;
    }
};
