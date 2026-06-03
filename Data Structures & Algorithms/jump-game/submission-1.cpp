class Solution {
public:
    bool canJump(vector<int>& nums) {
        // define T[i] = bool if the index is reachable
        vector<bool> T(nums.size());
        // base case
        T[0] = true;
        // recurrence relation - T[i] = (for j: 0 to i-1, T[j]==true and nums[j]+j==i)
        if (nums.size()>1) for (int i=1; i<nums.size(); i++) {
            int j = i;
            while (--j > -1) {
                if (T[j] and nums[j]+j>=i) {
                    T[i] = true;
                    break;
                }
                else T[i] = false;
            }
        }
        return T[nums.size()-1];
    }
};
