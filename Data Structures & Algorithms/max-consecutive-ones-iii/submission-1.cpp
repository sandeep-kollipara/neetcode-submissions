class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0, ones=0, zeroes=0, maximum=0;
        if (k==0){
            for (int i: nums) {
                if (i==0) ones=0;
                else ones++;
                maximum = max(maximum, ones);
            }
            return maximum;
        }
        while (j<nums.size()) {
            bool loop=false;
            // keep adding until there are k zeroes
            while (j<nums.size() and zeroes<=k) {
                if (nums[j]==0) zeroes++;
                else ones++;
                j++;
                loop=true;
            }
            if (loop and zeroes>k) {
                zeroes--;
                j--;
            }
            // save length
            maximum = max(ones+zeroes, maximum);
            // remove until k-1 zeroes
            while (i<j and zeroes>k-1) {
                if (nums[i]==1) ones--;
                else zeroes--;
                i++;
            }
        }
        return maximum;
    }
};