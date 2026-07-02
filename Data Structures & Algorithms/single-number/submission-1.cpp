class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a;
        for (int i=0; i<nums.size(); i++) {
            if (i==0) a = nums[i];
            else a = a^nums[i];
        }
        return 0^a;
    }
};
