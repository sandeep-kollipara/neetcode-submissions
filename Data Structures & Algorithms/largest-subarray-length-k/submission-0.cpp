class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int l=0;
        for (int i=0; i<nums.size()-k+1; i++) {
            int j=i, m=0;
            while (m<k and nums[j+m]>=nums[l+m]) {
                if (nums[j+m]>nums[l+m]) {
                    l=j;
                    break;
                }
                m++;
            }
        }
        return vector<int>(nums.begin()+l,nums.begin()+l+k);
    }
};
