class Solution {
public:
    bool isPowerOfTwo(int n) {
        int bit_counter = 0;
        while (n>0) {
            bit_counter+=(n & 1);
            n = (n >> 1);
        }
        return bit_counter==1;
    }
};