class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> deletion_idx;
        // corner case: size < 3
        if (nums.size() < 3) return nums.size();
        // general case: size >=3
        for (int i=0; i<nums.size()-2; i++) {
            if (nums[i]==nums[i+1] and nums[i+1]==nums[i+2]) {
                deletion_idx.push_back(i);
            }
        }
        int j=-1, k=0;
        for (int i=0; i<nums.size(); i++) {
            j++; // update
            nums[j] = nums[i];
            if (deletion_idx.empty() || k > (int)deletion_idx.size()-1) ; // (not) termination
            else {
                if (i==deletion_idx[k]) {
                    k++;
                    j--;
                }
            }
        }
        return nums.size()-deletion_idx.size();
    }
};