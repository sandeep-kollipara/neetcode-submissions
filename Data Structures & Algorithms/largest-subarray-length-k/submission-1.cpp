class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int maximum=INT_MIN, maxpos=-1;
        for (int i=0; i<nums.size()-k+1; i++) {
            if (nums[i]>maximum) {
                maximum=nums[i];
                maxpos=i;
            }
        }
        return vector<int>(nums.begin()+maxpos,nums.begin()+maxpos+k);
    }
};
