class Solution {
public:
    bool isPalindrome(int x) {
        string r = to_string(x);
        int i=0, j=r.length()-1;
        while (i<=j) {
            if (r[i]!=r[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};