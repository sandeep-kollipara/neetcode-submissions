class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z=0, n=0;
        while (n<nums.size()) {
            while (z<nums.size() and nums[z]!=0) {
                z++;
            }
            n=z;
            while (n<nums.size() and nums[n]==0) {
                n++;
            }
            if (n<nums.size()) {
                nums[z] = nums[n];
                nums[n] = 0;
            }
        }
    }
};