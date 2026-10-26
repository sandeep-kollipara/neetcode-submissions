class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0, maximum=0;
        unordered_map<int,int> hashmap;
        int i=0, j=0;
        while (j<nums.size()) {
            // extend the window to k
            while (j-i<k) {
                sum+=(long long)nums[j];
                hashmap[nums[j]]++;
                j++;
            }
            // check max
            if (hashmap.size()==k) maximum = max(maximum,sum);
            // shift by one
            sum-=(long long)nums[i];
            hashmap[nums[i]]--;
            if (hashmap[nums[i]]==0) hashmap.erase(nums[i]);
            i++;
            if (j<nums.size()) {
                sum+=(long long)nums[j];
                hashmap[nums[j]]++;
                j++;
            }
        }
        if (k<nums.size() and hashmap.size()==k) maximum = max(maximum,sum);
        return maximum;
    }
};
