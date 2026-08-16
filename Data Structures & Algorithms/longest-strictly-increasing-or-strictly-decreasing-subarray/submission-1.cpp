class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        bool inc=false, dec=false;
        int len=1, max_len=1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] < nums[i-1]) { // dec: 
                if (!dec) len=1;
                dec = true;
                inc = false;
            } else if (nums[i] == nums[i-1]) { // none: 
                dec = inc = false;
                len=1;
            } else { // inc: 
                if (!inc) len=1;
                inc = true;
                dec = false;
            }
            if (inc or dec) len++;
            max_len = max(len, max_len);
        }
        return max_len;
    }
};