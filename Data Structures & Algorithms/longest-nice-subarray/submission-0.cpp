class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> bitcounter(32, 0);
        auto extend=[&](int i){
            int j=0;
            while (i) {
                if (i&1) bitcounter[j]++;
                i>>=1;
                j++;
            }
        };
        auto shrink=[&](int i){
            int j=0;
            while (i) {
                if (i&1) bitcounter[j]--;
                i>>=1;
                j++;
            }
        };
        auto valid=[&](){
            for (int i: bitcounter) if (i > 1) return false;
            return true;
        };
        // sliding window - increase if AND is zero 
        // or else shorten only by one element from left
        int i=0, j=0, maxlen=1; // window i to j-1 inclusive
        while (j<nums.size()){
            // extend by 1
            extend(nums[j]);
            j++;
            // shorten if not valid until it is valid again
            while (not valid()) {
                shrink(nums[i]);
                i++;
            }
            // save the window size
            maxlen = max(maxlen, j-i);
        }
        return maxlen;
    }
};
