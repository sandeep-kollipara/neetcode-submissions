class Solution {
public:
    int numDecodings(string s) {
        // define T[i] = num of ways to decode until ith digit
        vector<int> T(s.length()+1);
        // base case
        T[0] = 1; // changed from 0 to 1 for ease of initialization
        // recurrence relation
        bool error=false;
        if (s.length()>0) for (int i=1; i<s.length()+1; i++){
            int extra_decoding=0;
            // last char check
            char last_char = s[i-1]; 
            if ((int)last_char==48) error = true; // error encountered
            // last 2 char check
            if (i>1){
                string last_2_chars = s.substr(i-2,2);
                int last_2_digits = 10*((int)last_2_chars[0]-48)+ ((int)last_2_chars[1]-48);
                if (last_2_digits > 9 and last_2_digits < 27) extra_decoding++;
                /*else if (last_2_digits <= 9) error2 = true;*/ // error detected only with 2 char check (NOT AN ERROR)
                cout << last_2_digits << " ";
            }
            cout << extra_decoding << endl;
            // final calculation
            if (not error) T[i] = T[i-1] + extra_decoding*T[i-2]; // default
            else if (extra_decoding) { // error recovery
                T[i] = T[i-2];
                error = false;
            }
            else return 0; // unrecoverable error
        }
        return T[s.length()];
    }
};
