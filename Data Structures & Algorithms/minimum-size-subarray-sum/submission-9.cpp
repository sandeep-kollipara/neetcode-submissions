class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (accumulate(nums.begin(), nums.end(), 0) < target) return 0;
        int i=0, j=0, min_len=INT_MAX;
        long sum=0;
        // initialize to a subarray sum of at least target
        while (sum < target) {
            sum+=nums[j];
            j++;
        }
        j--;
        min_len = j-i+1;
        //cout << i << "," << j << endl;
        // variable sliding window
        bool change = true;
        while (change) {//(sum > target) {//(j!=nums.size()-1) {
            change = false;
            // remove the initial elements until below target
            while (sum >= target) {
                sum-=nums[i];
                i++;
                change = true;
            }
            //cout << i << "," << j << endl;
            // note the size
            min_len = min(min_len, j-i+2); // add 1 more on the left
            // add the next elements until above target
            while (sum <= target and j+1 < nums.size()) { //  <= not just <
                j++;
                sum+=nums[j];
                change = true;
            }
        }
        return min_len;
    }
};