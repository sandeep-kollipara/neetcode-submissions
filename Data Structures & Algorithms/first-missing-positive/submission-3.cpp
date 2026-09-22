class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // remove negative numbers and numbers over nums size
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] <= 0 or nums[i] > nums.size()) nums[i] = -1;
        }
        // move the rest to their index (go to destination and exchange numbers)
        int temp, i=0;
        while (i < nums.size()) {
            if (nums[i]!=i+1 and nums[i]>0) {
                if (nums[nums[i]-1]==nums[i]) {
                    nums[i] = -1;
                } else {
                    temp = nums[nums[i]-1];
                    nums[nums[i]-1] = nums[i];
                    nums[i] = temp;
                }
                continue;
            }
            i++;
        }
        for (auto i: nums) cout << i << " ";
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]!=i+1) return i+1; 
        }
        return nums.size()+1;
    }
};