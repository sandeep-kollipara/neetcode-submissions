class Solution {
public:
    int maxScore(string s) {
        int glob_1 = 0;
        for (auto c: s) {
            if (c=='1')  glob_1++;
        }
        int left=0, right=glob_1, score=0;
        for (int i=0; i<s.length()-1; i++) { // i is last char of left string
            if (s[i]=='0') left++;
            else right--;
            score = max(score, left+right);
        }
        return score;
    }
};