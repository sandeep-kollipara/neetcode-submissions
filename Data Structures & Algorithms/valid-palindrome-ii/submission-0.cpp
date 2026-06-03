class Solution {
public:
    bool validPalindrome(string s) {
        function<bool(string)> isPalindrome=[](string s) {
            for (int i=0; i<s.length()/2; i++) {
                if (s[i]!=s[s.length()-i-1]) return false;
            }
            return true;
        };
        if (isPalindrome(s)) return true;
        for (int i=0; i<s.length(); i++) {
            string temp = s;
            temp.erase(i, 1);
            if (isPalindrome(temp)) return true;
        }
        return false;
    }
};