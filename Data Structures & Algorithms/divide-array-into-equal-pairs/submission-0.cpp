class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for (auto i: nums) hashmap[i]++;
        for (auto& [a, b]: hashmap) {
            if (b%2) return false;
        }
        return true;
    }
};