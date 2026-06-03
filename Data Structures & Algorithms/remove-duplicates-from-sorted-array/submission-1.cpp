class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> hash_set;
        int n_size = nums.size();
        for (int i=n_size-1; i>-1; i--) {
            if (hash_set.find(nums[i])==hash_set.end()) {
                hash_set.insert(nums[i]);
            } else {
                nums.erase(nums.begin()+i);
            }
        }
        return hash_set.size();
    }
};