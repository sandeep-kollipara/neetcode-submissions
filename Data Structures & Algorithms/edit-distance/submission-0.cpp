class Solution {
public:
    int minDistance(string word1, string word2) {
        // define T[i] = min num of operations to edit word1 to word2
        vector<vector<int>> T(word1.length()+1, vector<int>(word2.length()+1, 0));
        // base case
        for (int i=0; i<word1.length()+1; i++) T[i][0] = i;
        for (int j=0; j<word2.length()+1; j++) T[0][j] = j;
        // recurrence relation - T[i][j] = (if word1[i]==word2[j]) T[i-1][j-1] 
        // (else) min(T[i-1][j], T[i][j-1]) + 1
        if (word1.length()>0 and word2.length()>0) {
            for (int i=1; i<word1.length()+1; i++) {
                for (int j=1; j<word2.length()+1; j++) {
                    if (word1[i-1]==word2[j-1]) T[i][j] = T[i-1][j-1];
                    else T[i][j] = min(min(T[i-1][j], T[i][j-1]),T[i-1][j-1]) + 1;
                }
            }
        }
        for (int i=0; i<word1.length()+1; i++) {
            for (int j=0; j<word2.length()+1; j++) {
                cout << " " << T[i][j];
            }
            cout << endl;
        }
        return T[word1.length()][word2.length()];
    }
};
