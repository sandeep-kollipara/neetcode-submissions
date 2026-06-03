class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash_map;
        for (int i: nums) hash_map[i]++;
        unordered_set<int> hash_set;
        for (int i: nums) if (hash_map[i]>nums.size()/3) hash_set.insert(i);
        vector<int> majority;
        for (int i: hash_set) majority.push_back(i);
        return majority;
    }
};