class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1, temp;
        while (i<j) {
            while (i<nums.size() and nums[i]%2==0) i++;
            while (j>-1 and nums[j]%2) j--;
            if (i<j and i<nums.size() and j>-1) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        return nums;
    }
};