class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash_map;
        for (int i: nums) hash_map[i]++;
        for (const auto x: hash_map) {
            if (x.second > nums.size()/2) return x.first;
        }
    }
};