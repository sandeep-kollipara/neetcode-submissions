class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal, flips=0;
        while (x) {
            if (x&1) flips++;
            x>>=1;
        }
        return flips;
    }
};
