class Solution {
    // definition
    bool first=true;
    vector<int> C;
public:
    int numTrees(int n) {
        if (first) {
            first = false;
            C = vector<int>(20,-1); // constraint n = 0 to 19
        }
        // base case
        if (n<=1) {
            C[0] = C[1] = 1;
            return 1;
        }
        // memoization
        if (C[n]==-1) {
            int total=0;
            for (int i=0; i<n; i++) total+=(numTrees(i)*numTrees(n-i-1));
            C[n] = total;
            return total;
        } else return C[n];
    }
};
