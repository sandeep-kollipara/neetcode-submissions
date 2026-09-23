class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int reset=0, rev_reset=0;
        for (int i=1; i<nums.size(); i++){
            if (nums[i] >= nums[i-1]) reset++;
            if (nums[i] <= nums[i-1]) rev_reset++;
        }
        return reset==nums.size()-1 or rev_reset==nums.size()-1;
    }
};