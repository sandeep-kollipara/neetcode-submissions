class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashset1, hashset2;
        for (int i: nums1) hashset1.insert(i);
        for (int i: nums2) hashset2.insert(i);
        vector<vector<int>> result(2, vector<int>());
        for (int i: hashset1) {
            if (hashset2.find(i)!=hashset2.end()) hashset2.erase(i);
            else result[0].push_back(i);
        }
        for (int i: hashset2) result[1].push_back(i);
        return result;
    }
};