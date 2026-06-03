class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // define T[i][j] = num of ways to add upto i using the first j elements of nums
        vector<vector<int>> T(4001, vector<int>(nums.size()+1, -1));
        // base case
        for (int i=0; i<2000; i++) T[i][0] = 0;
        T[2000][0] = 1;
        for (int i=2001; i<4001; i++) T[i][0] = 0;
        // recurrence relation - T[i][j] = T[i-nums[j-1]][j-1] + T[i+nums[j-1]][j-1]
        if (nums.size()>0) for (int j=1; j<nums.size()+1; j++) {
            for (int i=1000; i<3001; i++) {
                T[i][j] = T[i-nums[j-1]][j-1] + T[i+nums[j-1]][j-1];
            }
        }
        return T[2000+target][nums.size()];
    }
};
