class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0], max_sum=nums[0], max_idx=-1;
        if (nums.size()>1) for (int i=1; i<nums.size(); i++) {
            sum+=nums[i];
            if (sum > max_sum) {
                max_sum = sum;
                max_idx = i;
            }
        }
        sum=nums[max_idx];
        max_sum=nums[max_idx];
        int min_idx=max_idx;
        if (nums.size()>1) for (int i=max_idx-1; i>-1; i--) {
            sum+=nums[i];
            if (sum > max_sum) {
                max_sum = sum;
                min_idx = i;
            }
        }
        cout << min_idx << ", " << max_idx;
        if (min_idx!=-1 and max_idx!=-1) return accumulate(nums.begin()+min_idx,nums.begin()+max_idx+1,0);
        else return *max_element(nums.begin(), nums.end());
    }
};
