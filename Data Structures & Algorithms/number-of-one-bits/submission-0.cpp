class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0, quo, rem = n;
        cout << n;
        for (int i=31; i>-1; i--) {
            quo = rem/(int)pow(2,i);
            rem = rem%(int)pow(2,i);
            if (quo) bits++;
        }
        return bits;
    }
};
