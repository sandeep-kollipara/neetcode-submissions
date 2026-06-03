class Solution {
public:
    string longestPalindrome(string s) {
        // define T[i] = length of longest palindrome substring ending in ith character
        vector<int> T(s.length()+1);
        // base case
        T[0] = 0;
        T[1] = 1;
        // recurrence relation - 
        for (int i=2; i<s.length()+1; i++) {
            // default case
            T[i] = 1; 
            // extends previous palindrome
            if (i > T[i-1]+1) if (s[i-T[i-1]-2]==s[i-1]) T[i] = T[i-1] + 2;
            // intermediate case
            string s_intermediate = s.substr(i-1-T[i-1], T[i-1]+1);
            while (s_intermediate.length()>0) {
                bool is_palindrome = true;
                for (int j=0; j<floor(s_intermediate.length()/2); j++) {
                    if (s_intermediate[j]!=s_intermediate[s_intermediate.length()-1-j]) is_palindrome = false;
                }
                // choose the maximum
                if (is_palindrome) if (s_intermediate.length() > T[i]) T[i] = s_intermediate.length(); //T[i] = max(T[i], s_intermediate.length());
                // update
                s_intermediate = s_intermediate.substr(1, s_intermediate.length()-1);
            }
        }
        for (int t: T) cout << t << " ";
        cout << endl;
        int T_max = *max_element(T.begin(), T.end());
        int i_max = distance(T.begin(), find(T.begin(), T.end(), T_max));
        return s.substr(i_max-T_max, T_max);
    }
};
