class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hashmap;
        for (char c: s) hashmap[c]++;
        int palindrome_len = 0;
        for (auto& [a, b]: hashmap) {
            palindrome_len+=(b - b%2);
        }
        if (palindrome_len < s.length()) return palindrome_len+1;
        else return palindrome_len;
    }
};