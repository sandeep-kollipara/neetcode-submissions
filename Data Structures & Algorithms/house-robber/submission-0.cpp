class Solution {
public:
    int rob(vector<int>& nums) {
        // define T[i] = max money robbable by including ith house and before
        vector<int> T(nums.size()+1);
        // base case
        T[0] = 0;
        T[1] = nums[0];
        T[2] = nums[1];
        // reccurence relation - max of i-2 or i-3 instance has to be selected with ith
        if (nums.size()>2) for (int i=3; i<nums.size()+1; i++) T[i] = nums[i-1] + max(T[i-2],T[i-3]);
        return *max_element(T.begin(), T.end());
    }
};
