class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // definition of T[] = the largest sum of the array starting from first idx to current idx
        vector<int> T(nums.size(), 0);
        /*int min = 1e9, min_idx = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < min) {
                min_idx = i;
                min = nums[i];
            }
        }
        vector<int> mins;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == min) {
                mins.push_back(i);
                cout << i << " ";
            }
        }*/
        // base case
        vector<int> max_sum;
        //for (int min_idx: mins) {
        for (int min_idx=0; min_idx<nums.size(); min_idx++){
            for (int i=0; i < nums.size(); i++){
                T[i] = nums[(min_idx+i)%nums.size()];
            }
            // recurrence relation - kadane's algorithm
            for (int i=1; i < T.size(); i++) {
                T[i] = max(T[i-1] + T[i], T[i]);
            }
            max_sum.push_back(*max_element(T.begin(), T.end()));
        }
        return *max_element(max_sum.begin(), max_sum.end());
    }
};