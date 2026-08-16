class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=accumulate(nums.begin(), nums.end(), 0), left=0, right=total;
        for (int i=0; i<nums.size(); i++) {
            if (i>0) left+=nums[i-1];
            right-=nums[i];
            if (left==right) return i;
        }
        return -1;
    }
};