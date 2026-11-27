class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits2=0, bits1=0;
        // calculate 1 bits in num2
        int temp = num2;
        while (temp) {
            if (temp&1) bits2++;
            temp>>=1;
        }
        // calculate 1 bits in num1
        temp = num1;
        while (temp) {
            if (temp&1) bits1++;
            temp>>=1;
        }
        // cases
        cout << bits1 << " " << bits2 << endl;
        if (bits1 == bits2) return num1;
        else if (bits1 > bits2) {
            // truncate nums1 from left or keep the leftover from right
            int leftover = bits1 - bits2, pos=0;
            num2 = 0;
            while (leftover or bits1) {
                if (num1&1){ // copy the 1s
                    if (not leftover) num2|=(1<<pos);
                    else leftover--;
                    bits1--;
                }
                num1>>=1;
                pos++;
            }
        } else {
            // construct x from nums1 using leftover bits in 0s of nums1
            int leftover = bits2 - bits1, pos=0;
            num2=num1;
            while (leftover) {
                if (not (num1&1)){ // insert in 0s
                    num2|=(1<<pos);
                    leftover--;
                }
                num1>>=1;
                pos++;
            }
        }
        return num2;
    }
};
