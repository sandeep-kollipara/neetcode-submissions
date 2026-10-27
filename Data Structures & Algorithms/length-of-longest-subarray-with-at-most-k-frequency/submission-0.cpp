class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        int i=0, j=0, maximum=0;
        while (j<nums.size()) {
            bool loop=false;
            // extend the window until freq is more than k
            while (j<nums.size() and (j-i<k or hashmap[nums[j-1]]<=k)) {
                hashmap[nums[j]]++;
                j++;
                loop=true;
            }
            if ((j<nums.size() or (j-i>=k and hashmap[nums[j-1]]>k)) and loop) {
                j--;
                hashmap[nums[j]]--;
            }
            // save the maximum
            maximum = max(maximum, j-i);
            // shrink the window by one
            hashmap[nums[i]]--;
            i++;
        }
        if (k<nums.size()) maximum = max(maximum, j-i);
        return maximum;
    }
};
