class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        //vector<int> prefixsum(nums), suffixsum(nums);
        long long temp=nums[0], maxscore1=INT_MIN, maxscore2=INT_MIN;
        for (int i=1; i<nums.size(); i++) { // forward sum
            maxscore1=max(maxscore1,temp);
            temp+=nums[i];
        }
        maxscore1=max(maxscore1,temp);
        temp=nums[nums.size()-1];
        for (int i=nums.size()-2; i>-1; i--) { // backward sum
            maxscore2=max(maxscore2,temp);
            temp+=nums[i];
        }
        maxscore2=max(maxscore2,temp);
        return max(maxscore1,maxscore2);
    }
};
