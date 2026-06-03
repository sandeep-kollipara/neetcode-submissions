class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (int i=0; i<nums.size(); i++) {
            if (hash_set.find(nums[i])==hash_set.end()) hash_set.insert(nums[i]);
            else hash_set.erase(nums[i]);
        }
        for (int i: hash_set) return i;
    }
};
