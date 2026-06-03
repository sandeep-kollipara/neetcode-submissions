class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // define T[i] = num of ways to add upto i using nums with repetition
        vector<int> T(target+1);
        // base case
        T[0] = 1;
        // recurrence relation = T[i] = j=0->nums.size()-1 SUM T[i-j] given i-j>=0
        if (target>0) for (int i=1; i<target+1; i++) {
            int t=0;
            for (int j=0; j<nums.size(); j++) {
                if (i>=nums[j]) t+=T[i-nums[j]];
            }
            T[i] = t;
        }
        return T[target];
    }
};