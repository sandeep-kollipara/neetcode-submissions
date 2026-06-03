class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> nums_2(2*nums.size(), 0);
        for (int i=0; i<nums.size(); i++) {
            nums_2[i] = nums[i];
            nums_2[i+nums.size()] = nums[i];
        }
        return nums_2;
    }
};