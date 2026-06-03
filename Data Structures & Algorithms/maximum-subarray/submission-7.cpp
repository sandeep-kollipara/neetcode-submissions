class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // definition of T[] = the largest sum of the array starting from first idx to current idx
        vector<int> T(nums);
        // base case
        T[0] = nums[0];
        // recurrence relation - kadane's algorithm
        for (int i=1; i < T.size(); i++) {
            T[i] = max(T[i-1] + T[i], T[i]);
        }
        return *max_element(T.begin(), T.end());
    }
};
