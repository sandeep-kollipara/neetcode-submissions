class Solution {
public:
    bool check(vector<int>& nums) {
        int reset=0;
        for (int i=1; i<nums.size(); i++) if (nums[i] < nums[i-1]) reset++;
        if (nums[nums.size()-1] > nums[0]) reset++;
        return reset <= 1;
    }
};