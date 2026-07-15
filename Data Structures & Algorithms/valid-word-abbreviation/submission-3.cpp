class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        string num;
        int skip=0, j=0;
        for (char c: abbr) {
            if ((int)c > 47 and (int)c < 58) num+=c;
            else {
                if (j>=word.size()) return false;
                if (num!="") {
                    if (num[0]=='0') return false;
                    skip = stoi(num);
                    num = "";
                }
                if (skip) {
                    j+=skip;
                    skip=0;
                }
                if (j<word.size() and c!=word[j]) return false;
                j++;
            }
        }
        if (num!="") {
            if (num[0]=='0') return false;
            skip = stoi(num);
            num = "";
        }
        if (skip) {
            j+=skip;
            skip=0;
        }
        if (j==word.size()) return true;
        return false;
    }
};