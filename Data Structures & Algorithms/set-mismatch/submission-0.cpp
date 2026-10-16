class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //int gap = nums.size()*(nums.size()+1)/2 - accumulate(nums.begin(), nums.end(), 0);
        int dup, orig;
        vector<bool> bitmap(nums.size(), false);
        for (int i: nums) {
            if (not bitmap[i-1]) bitmap[i-1] = true;
            else dup = i;
        }
        for (int i=1; i<=nums.size(); i++) {
            if (not bitmap[i-1]) {
                orig = i;
                break;
            }
        }
        return {dup, orig};
    }
};