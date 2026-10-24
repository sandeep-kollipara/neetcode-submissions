class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0, close=0;
        for (char c: s) {
            if (c=='(') open++;
            else if (c==')' and open) open--;
            else close++;
        }
        return open+close;
    }
};
