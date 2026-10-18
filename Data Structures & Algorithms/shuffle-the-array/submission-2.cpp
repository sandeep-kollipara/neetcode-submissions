class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        auto converter=[&](int i){
            if (i<n) return 2*i;
            return 2*(i%n)+1;
        };
        vector<int> arr(nums);
        int idx=0, tgt, temp=nums[idx], temp2;
        while (idx<nums.size()) {
            tgt = converter(idx);
            arr[tgt] = nums[idx];
            idx++;
        }
        return arr;
    }
};
