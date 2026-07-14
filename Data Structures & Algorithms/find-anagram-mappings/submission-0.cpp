class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> hashmap;
        for (int i=0; i<nums2.size(); i++) {
            hashmap[nums2[i]].push_back(i);
        }
        vector<int> mapping;
        for (int j=0; j<nums1.size(); j++) {
            mapping.push_back(hashmap[nums1[j]].back());
            hashmap[nums1[j]].pop_back();
        }
        return mapping;
    }
};
