class Solution {
public:
    string encode(int num) {
        string out;
        //cout << (int)log2(num);
        int num2 = num, num3 = 0;
        num2++;
        while (num2/=2) {
            num3++;
        }
        int num4 = num - round(pow(2, num3)) + 1;
        for (int i=0; i < num3; i++) {
            out = to_string(num4%2) + out;
            num4/=2;
        }
        return out;
    }
};
