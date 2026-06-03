class Solution {
public:
    int rob(vector<int>& nums) {
        //edge case
        if (nums.size()==0) return 0;
        else if (nums.size()==1) return nums[0];
        // importing process from House Robber I
        function<int(vector<int>)> house_robber_i=[&](vector<int> nums){
            // define T[i] = max money robbable by including ith house and before
            vector<int> T(nums.size()+1);
            // base case
            T[0] = 0;
            T[1] = nums[0];
            T[2] = nums[1];
            // reccurence relation - max of i-2 or i-3 instance has to be selected with ith
            if (nums.size()>2) for (int i=3; i<nums.size()+1; i++) T[i] = nums[i-1] + max(T[i-2],T[i-3]);
            return *max_element(T.begin(), T.end());
        };
        vector<int> nums1 = vector<int>(nums.begin()+1, nums.end());
        vector<int> nums2 = vector<int>(nums.begin(), nums.end()-1);
        return max(house_robber_i(nums1),house_robber_i(nums2));
    }
};
