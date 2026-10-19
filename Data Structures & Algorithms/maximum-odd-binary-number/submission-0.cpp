class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0, zeroes=0;
        for (char c: s) {
            if (c=='1') ones++;
            else zeroes++;
        }
        s[s.length()-1] = '1';
        ones--;
        while (ones) s[s.length()-(ones--)-zeroes-1]='1';
        while (zeroes) s[s.length()-(zeroes--)-1]='0';
        return s;
    }
};