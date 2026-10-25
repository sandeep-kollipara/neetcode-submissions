class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones=0, zeroes=0, extras=0, maximum=0;
        for (auto& i: nums) {
            if (i) ones++;
            else zeroes++;
            if (zeroes > 1) {
                zeroes=1;
                ones=extras;
                extras=0;
            } else if (zeroes) {
                if (i) extras++;
            }
            maximum = max(maximum, ones+zeroes);
        }
        return maximum;
    }
};
