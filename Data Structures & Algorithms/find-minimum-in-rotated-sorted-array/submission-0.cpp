class Solution {
public:
    int findMin(vector<int> &nums) {
        int mid, low = 0;
        int high = nums.size()-1;
        while(high-low>1){
            mid = ceil((low + high)/2);
            cout << nums[low] << " " << nums[mid] << " " << nums[high] <<endl;
            if (nums[mid] < nums[high]) high = mid;
            else low = mid;
        }
        if (nums[low]<nums[high]) return nums[low];
        else return nums[high];
    }
};
