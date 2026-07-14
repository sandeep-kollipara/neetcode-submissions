class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int max_len=0;
        for (auto a: words) max_len = (max_len > a.length()) ? max_len : a.length();
        max_len = (max_len > words.size()) ? max_len : words.size();
        //cout << max_len << endl;
        char a, b;
        for (int i=0; i<max_len; i++) {
            for (int j=0; j<i; j++) {
                a = ' ';
                b = ' ';
                if (j<words.size() and i<words[j].size()) {
                    a = words[j][i];
                }
                if (i<words.size() and j<words[i].size()) {
                    b = words[i][j];
                }
                if (a!=b) return false;
            }
        }
        return true;
    }
};
