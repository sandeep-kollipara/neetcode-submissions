class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // initialize window
        unordered_set<int> hashset;
        for(int i=0; i < min((int)nums.size(), k); i++) {
            if (hashset.find(nums[i])!=hashset.end()) return true;
            hashset.insert(nums[i]);
        }
        // sliding window
        int l = 0, r;
        while (l < nums.size()) {
            if (l+k < nums.size()) r = l + k - 1;
            else break;
            r++;
            if (hashset.find(nums[r])!=hashset.end()) return true;
            else hashset.insert(nums[r]);
            hashset.erase(nums[l]);
            l++;
        }
        return false;
    }
};