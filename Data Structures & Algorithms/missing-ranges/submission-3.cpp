class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.size()==0) return {{lower, upper}};
        vector<vector<int>> missing_ranges;
        if (nums[0]-lower>0) missing_ranges.push_back({lower, nums[0]-1});
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]-nums[i-1]>1) missing_ranges.push_back({nums[i-1]+1,nums[i]-1});
        }
        if (upper-nums[nums.size()-1]>0) missing_ranges.push_back({nums[nums.size()-1]+1, upper});
        return missing_ranges;
    }
};
