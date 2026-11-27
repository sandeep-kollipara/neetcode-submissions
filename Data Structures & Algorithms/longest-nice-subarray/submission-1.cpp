class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // sliding window - increase if AND is zero 
        // or else shorten only by one element from left
        int i=0, j=0, maxlen=1, mask=0; // window i to j-1 inclusive
        while (j<nums.size()){
            // extend by 1 only if valid
            if (not (mask&nums[j])) {
                mask|=nums[j];
                j++;
            }
            // shorten by 1 if not valid until it is valid again
            else {
                mask^=nums[i];
                i++;
            }
            // save the window size
            maxlen = max(maxlen, j-i);
        }
        return maxlen;
    }
};
