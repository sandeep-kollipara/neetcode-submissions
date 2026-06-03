class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal=nums.size()-1;
        if (nums.size()>1) for (int j=nums.size()-2; j>-1; j--) {
            if (nums[j]>=goal-j) goal = j;
        }
        return goal==0;
    }
};
