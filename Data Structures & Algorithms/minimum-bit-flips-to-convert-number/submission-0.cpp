class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal, flips=0;
        while (x) {
            if (x%2) flips++;
            x/=2;
        }
        return flips;
    }
};
