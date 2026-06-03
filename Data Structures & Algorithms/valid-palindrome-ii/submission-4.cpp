class Solution {
public:
    bool validPalindrome(string s) {
        /*function<bool(string)> isPalindrome=[](string s) {
            for (int i=0; i<s.length()/2; i++) {
                if (s[i]!=s[s.length()-i-1]) return false;
            }
            return true;
        };
        if (isPalindrome(s)) return true;*/
        int l=0, r=s.length()-1;
        bool except=false;
        while (l<r) {
            if (s[l]==s[r]) {
                l++;
                r--;
            } else if (not except) {
                except = true;
                if (r - l > 2) { // 2 char check
                    if (s[l+1]==s[r] and s[l+2]==s[r-1]) l++;
                    else if (s[l]==s[r-1] and s[l+1]==s[r-2]) r--;
                    else return false;
                } else { // 1 char check
                    if (s[l+1]==s[r]) l++;
                    else if (s[l]==s[r-1]) r--;
                    else return false;
                }
            } else return false;
        }
        return true;
    }
};