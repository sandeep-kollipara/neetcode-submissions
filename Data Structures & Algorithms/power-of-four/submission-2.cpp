class Solution {
public:
    bool isPowerOfFour(int n) {
        int bit_counter=0, pos=1, bit_pos, m=n;
        while (m) {
            if (m%2){
                bit_counter++;
                bit_pos=pos;
            }
            m/=2;
            pos++;
        }
        return n>0 and bit_counter==1 and bit_pos%2;
    }
};
