class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int p=0;
        while (p<nums.size() and nums[p]<0) p++;
        int i=p-1, j=p;
        while (i>-1 or j<nums.size()) {
            if (i==-1 or (j<nums.size() and nums[i]*nums[i] > nums[j]*nums[j])) {
                result.push_back(nums[j]*nums[j]);
                j++;
            } else if (j==nums.size() or (i>-1 and nums[i]*nums[i] <= nums[j]*nums[j])) {
                result.push_back(nums[i]*nums[i]);
                i--;
            }
        }
        return result;
    }
};