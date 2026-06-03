class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long int bits = 0, quo, rem = n;
        cout << n << endl;
        for (int i=31; i>-1; i--) {
            quo = rem/(long int)pow(2,i);
            cout << quo;
            //cout << rem << endl;
            //rem = rem%(double)pow(2,i);
            rem = fmod(rem,(long int)pow(2,i));
            if (quo) bits+=(long int)pow(2,31-i);
        }
        return bits;
    }
};
