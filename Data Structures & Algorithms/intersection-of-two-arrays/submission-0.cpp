class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashset;
        vector<int> intersect;
        for (int i: nums1) hashset.insert(i);
        for (int i: nums2) if (hashset.find(i)!=hashset.end()) hashset.insert(-i); //intersect.push_back(i);
        for (int i: hashset) if (i<0) intersect.push_back(-i);
        return intersect;
    }
};