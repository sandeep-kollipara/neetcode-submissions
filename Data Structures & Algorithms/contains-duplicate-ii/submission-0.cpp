class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> hash_map;
        vector<int> duplicates;
        for (int i=0; i<nums.size(); i++) {
            if (hash_map.find(nums[i])==hash_map.end()) {
                hash_map[nums[i]] = {i};
            } else {
                duplicates.push_back(nums[i]);
                hash_map[nums[i]].push_back(i);
            }
        }
        for (int i: duplicates) {
            vector<int> indices = hash_map[i];
            for (int j=0; j<indices.size()-1; j++) {
                indices[j+1]-=indices[j];
            }
            for (int j=1; j<indices.size(); j++) {
                if (indices[j]<=k) return true;
            }
        }
        return false;
    }
};