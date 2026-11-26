class Solution {
public:
    string encode(int num) {
        string out;
        //cout << (int)log2(num);
        int num2 = (int)log2(num+1), num3 = num - pow(2, num2) + 1;
        for (int i=2; i <= num+1; i*=2) {
            out = to_string(num3%2) + out;
            num3/=2;
        }
        return out;
    }
};
