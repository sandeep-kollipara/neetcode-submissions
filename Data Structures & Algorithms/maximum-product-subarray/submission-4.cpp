class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // define T[i] = max product of subarray ending in ith element
        vector<int> T(nums.size()+1);
        // base case - T[0] is nonsensical so unused
        T[1] = nums[0];
        // recurrence relation
        if (nums.size()>1) for (int i=2; i<nums.size()+1; i++) {
            int prod = nums[i-1], max_prod = nums[i-1];
            for (int j=i-1; j>-1; j--) {
                prod*=nums[j-1];
                if (max_prod < prod) max_prod = prod;
            }
            T[i] = /*max(nums[i-1], nums[i-1]*T[i-1])*/ max_prod;
        }
        return *max_element(T.begin()+1, T.end());
    }
};
