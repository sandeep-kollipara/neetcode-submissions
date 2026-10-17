class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i]>=i+1 and nums[i+1]<i+1) return i+1;
        }
        if (nums[nums.size()-1]>=nums.size()) return nums.size();
        return -1;
    }
};