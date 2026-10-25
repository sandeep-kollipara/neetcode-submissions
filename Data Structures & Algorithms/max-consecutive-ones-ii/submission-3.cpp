class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0, j=-1, zeroes=0, maximum=0;
        while (j<(int)nums.size()){
            // extend window until second zero is encountered
            while (j<(int)nums.size() and zeroes < 2) {
                j++;
                if (j<(int)nums.size() and nums[j]==0) zeroes++;
            }
            // save the maximum
            maximum = max(maximum, j-i);
            // shrink window until first zero is expelled
            while (i<=j and zeroes > 1) {
                if (nums[i]==0) zeroes--;
                i++;
            }
        }
        return maximum;
    }
};
