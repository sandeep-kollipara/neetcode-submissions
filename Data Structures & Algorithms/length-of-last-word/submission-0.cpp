class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_word_len=0;
        for (int i=s.length()-1; i>-1; i--) {
            if (s[i]!=' ') last_word_len++;
            else if (last_word_len!=0) break;
        }
        return last_word_len;
    }
};