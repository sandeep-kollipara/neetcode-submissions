class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n_size = nums.size();
        for (int i=n_size-1; i>0; i--) {
            if (nums[i]==nums[i-1]) {
                nums.erase(nums.begin()+i);
            }
        }
        return nums.size();
    }
};