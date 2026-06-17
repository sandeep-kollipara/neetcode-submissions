class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // brute force - search the sliding widow every pass so O(kn) worst case
        vector<int> result(nums.size()-k+1, 0);
        // initalize
        // traverse
        int max_ele;
        for (int i=0; i<nums.size()-k+1; i++) {
            max_ele = INT_MIN;
            for (int j=i; j<i+k; j++) {
                if (nums[j]>max_ele) max_ele = nums[j];
            }
            result[i] = max_ele;
        }
        return result;
    }
};
