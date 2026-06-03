class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        /* Removing the spaces and non-alphanumerics */
        for (char c: s){
            if ((int)c > 47 and (int)c < 58) str+=c;
            else if ((int)c > 64 and (int)c < 91) str+=char((int)c+32);
            else if ((int)c > 96 and (int)c < 123) str+=c;
            else continue;
        }
        cout << str;
        for (int i=0; i < str.length()/2; i++){
            if (str[i] != str[str.length()-i-1]){
                return false;
            }
        }
        return true;
    }
};
