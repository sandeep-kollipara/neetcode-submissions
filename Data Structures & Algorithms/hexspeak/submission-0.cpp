class Solution {
public:
    string toHexspeak(string num) {
        auto translate=[](int i) -> string {
            string s;
            if (i==0) return "O";
            else if (i==1) return "I";
            else if (i>9 and i<16) {
                return s+(char)(55+i);
            }
            return "ERROR";
        };
        long long val = stoll(num);
        string trans;
        while (val) {
            int rem = val%16;
            val/=16;
            if (rem>1 and rem<10) return "ERROR";
            trans=translate(rem)+trans;
        }
        return trans;
    }
};
