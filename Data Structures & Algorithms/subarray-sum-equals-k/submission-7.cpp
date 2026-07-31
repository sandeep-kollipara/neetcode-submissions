class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // create prefix sum
        for (int i=1; i<nums.size(); i++) {
            nums[i]+=nums[i-1];
        }
        // loadup hashmap and calculate a running sum
        unordered_map<int,int> hashmap;
        int running_count=0;
        for (auto i: nums) {
            hashmap[i]++;
            running_count+=hashmap[i-k];
        }
        if (k==0) {
            running_count=hashmap[k];
            for (auto& [a, b]: hashmap) {
                if (b>0) running_count+=(b*(b-1)/2);
            }
            return running_count;
        }
        return running_count+hashmap[k];
    }
};