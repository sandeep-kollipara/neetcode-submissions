class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid=floor(high/2);
        while (mid!=low) {
            if (target > nums[mid]) low = mid;
            else if (target < nums[mid]) high = mid;
            else return mid;
            mid=floor((low+high)/2);
        }
        if (nums[mid]==target) return mid;
        else if (nums[high]==target) return high;
        else return -1;
    }
};
