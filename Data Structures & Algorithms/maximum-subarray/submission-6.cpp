class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        bool land = false, sea = true;
        int maximum=-1001, sum=-1001, max_sum = -1001;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < 0 and land == true) { // wrap the sum
                if (max_sum < sum) max_sum = sum;
                //sum = 0;
                sum+=nums[i];
                land = false;
            } else if (nums[i] < 0 and land == false) { // ignore
                //land = false;
                sum+=nums[i];
            } else if (nums[i] > 0 and land == true) { // continue the sum
                sum+=nums[i];
                //land = true;
                //sea = false;
            } else { // start the sum
                if (sum > 0) sum+=nums[i];
                else sum = nums[i];
                land = true;
                sea = false;
            }
            if (nums[i] > maximum) maximum =  nums[i];
        }
        if (max_sum < sum) max_sum = sum;
        if (sea) return maximum;
        else return max_sum;
    }
};
