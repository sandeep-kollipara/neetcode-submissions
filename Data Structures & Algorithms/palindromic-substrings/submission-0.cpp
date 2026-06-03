class Solution {
public:
    int countSubstrings(string s) {
        // define T[i] = num of palindrome substrings until ith char
        vector<int> T(s.length()+1);
        // base case
        T[0] = 0;
        T[1] = 1;
        // recurrence relation
        if (s.length()>1) for (int i=2; i<s.length()+1; i++) {
            int new_palindromes=0, j=i-1;
            while (j>-1){
                bool is_palindrome = true;
                string substring = s.substr(j,i-j);
                for (int k=0; k<floor(substring.length()/2); k++){
                    if (substring[k]!=substring[substring.length()-k-1]) is_palindrome = false;
                }
                if (is_palindrome) new_palindromes++;
                j--;
                cout << substring << " " ;
            }
            cout << new_palindromes << " ";
            cout << endl;
            T[i] = T[i-1] + new_palindromes;
        }
        return T[s.length()];
    }
};
