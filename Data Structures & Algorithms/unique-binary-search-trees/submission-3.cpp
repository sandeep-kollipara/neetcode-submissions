class Solution {
    // definition
    vector<int> C;
public:
    int numTrees(int n) {
        // definition - C[i] is the number of bst trees with i distinct nodes
        vector<int> C(n+1,0);
        // base case
        C[0] = C[1] = 1;
        // recurrence relation
        for (int i=2; i<=n; i++) {
            for (int j=0; j<i; j++) C[i]+=C[j]*C[i-j-1] ;
        }
        return C[n];
    }
};
