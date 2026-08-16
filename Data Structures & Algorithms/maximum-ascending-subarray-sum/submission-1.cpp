class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        bool inc=false;
        int sum=0, maxsum;
        if (nums.size()) sum=nums[0];
        maxsum=sum;
        for (int i=1; i<nums.size(); i++) {
            // Two possibilities: next > curr or otherwise
            if (nums[i] > nums[i-1]) {
                inc = true;
            } else {
                inc = false;
                sum=nums[i];
            }
            if (inc) sum+=nums[i];
            maxsum = max(sum, maxsum);
        }
        return maxsum;
    }
};