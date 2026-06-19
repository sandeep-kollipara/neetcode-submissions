class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int delta, j=0;
        for (int i=0; i<nums.size()-1; i++) {
            delta = nums[i+1] - nums[i] - 1;
            if (j + delta < k) j+=delta;
            else return nums[i] + k - j;
        }
        return nums[nums.size()-1] + k - j;
    }
};
