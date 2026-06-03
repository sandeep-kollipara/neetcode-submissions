class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // define T[i][j] = longest common subsequence length of first i chars of text1 and j chars of text2
        vector<vector<int>> T(text1.length()+1, vector<int>(text2.length()+1));
        // base case
        for (int i=0; i<text1.length(); i++) T[i][0] = 0;
        for (int j=0; j<text2.length(); j++) T[0][j] = 0;
        // recurrence relation T[i][j] = (if t1[i]=t2[j]) T[i-1][j-1]+1 (else) max(T[i-1][j],T[i][j-1])
        if (text1.length()>0 and text2.length()>0) for (int i=1; i<text1.length()+1; i++) {
            for (int j=1; j<text2.length()+1; j++) {
                if (text1[i-1]==text2[j-1]) T[i][j] = 1 + T[i-1][j-1];
                else T[i][j] = max(T[i-1][j],T[i][j-1]);
            }
        }
        return T[text1.length()][text2.length()];
    }
};
