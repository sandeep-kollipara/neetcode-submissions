class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // idx = val - 1
        int val, idx=0;
        //cout << (not idx < nums.size()) << endl;
        while (idx < nums.size()) {
            cout << nums[idx] << endl;
            val = nums[idx];
            if (val > 0 and nums[val-1] > 0) nums[val-1] = -nums[val-1]; // flip the target
            else if (val > 0 and nums[val-1] < 0) return val;
            else if (val < 0 and nums[-val-1] > 0) nums[-val-1] = -nums[-val-1];
            else if (val < 0 and nums[-val-1] < 0) return -val;
            idx++;
        }
        return 0;
    }
};
