class Solution {
public:
    int minOperations(string s) {
        int zero_start=0, one_start=0;
        for (int i=0; i<s.length(); i++) {
            if (s[i]=='0' and i%2) zero_start++;
            else if (s[i]=='0') one_start++;
            else if (s[i]=='1' and i%2) one_start++;
            else zero_start++;
        }
        return min(zero_start, one_start);
    }
};