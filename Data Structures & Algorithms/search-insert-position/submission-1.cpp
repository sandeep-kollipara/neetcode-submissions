class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1, mid;
        if (nums[high] < target) return high+1;
        else if (nums[low] > target) return low; // out of bounds edge cases
        while (high - low > 1) {
            mid = (low + high)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]>target) high = mid;
            else low = mid;
        }
        return high;
    }
};