class Solution {
public:
    bool isValid(string s) {
        int j=0;
        vector<char> arr(s.length(), '\0');
        for(int i=0; i<s.length(); i++) {
            switch (s[i]) {
                case '(':
                    arr[j] = '(';
                    break;
                case '{':
                    arr[j] = '{';
                    break;
                case '[':
                    arr[j] = '[';
                    break;
                case ')':
                    if (j==0) return false;
                    else if (arr[j-1] == '(') j-=2;
                    else return false;
                    break;
                case '}':
                    if (j==0) return false;
                    else if (arr[j-1] == '{') j-=2;
                    else return false;
                    break;
                case ']':
                    if (j==0) return false;
                    else if (arr[j-1] == '[') j-=2;
                    else return false;
                    break;
                default:
                    j--;
            }
            j++;
        }
        return j==0;
    }
};
