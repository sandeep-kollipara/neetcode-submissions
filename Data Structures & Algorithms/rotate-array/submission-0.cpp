class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums2(nums.size());
        int j, n_size=nums.size();
        for (int i=0; i<nums.size(); i++) {
            j = i+k;
            if (i+k >= n_size) j = (i+k)%n_size;
            nums2[j] = nums[i];
        }
        nums = nums2;
    }
};