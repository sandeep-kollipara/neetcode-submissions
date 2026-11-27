class Solution {
public:
    string findKthBit(int n, int k) {
        int flips=0;
        while (n > 1) {
            if (k == pow(2,n-1)) {
                return to_string(1-flips%2);
                //return "1";
            } else if (k > pow(2,n-1)) {
                flips++;
                k = pow(2, n) - k;
            }
            n--;
            cout << k << " " << n << endl;
        }
        return to_string(flips%2);
    }
};
