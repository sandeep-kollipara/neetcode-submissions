class Solution {
public:
    long long minEnd(int n, int x) {
        // x is the frame, fill the 0s with n-1
        long long result=x;
        n--;
        int pos=0;
        while (n) {
            //cout << (x&1) << endl;
            if (not (x&1)) { // position in result/x is zero
                if (n&1) result|=(1LL<<pos);
                //cout << pos << " " << (n&1) << endl;
                n>>=1;
            }
            x>>=1;
            pos++;
        }
        return result;
    }
};