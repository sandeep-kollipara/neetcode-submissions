class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        auto cmp=[](const int a, const int b){
            return a > b;
        };
        sort(nums.begin(), nums.end(), cmp);
        int a = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i-1]==nums[i]) {
                a = -1;
            } else if (a!=-1 and nums[i-1]!=nums[i]) {
                break;
            } else {
                a = nums[i];
            }
        }
        return a;
    }
};
