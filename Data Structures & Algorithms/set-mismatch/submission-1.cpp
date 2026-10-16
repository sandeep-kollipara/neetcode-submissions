class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int gap = nums.size()*(nums.size()+1)/2 - accumulate(nums.begin(), nums.end(), 0);
        int dup, ori;
        for (int i: nums) {
            if (nums[abs(i)-1]<0) dup = abs(i);
            else nums[abs(i)-1]*=(-1);
        }
        cout << gap;
        ori = dup+gap;
        return {dup, ori};
    }
};