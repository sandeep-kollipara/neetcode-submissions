class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for (auto& i: nums) hashmap[i]++;
        int good_pairs=0;
        for (auto& [a, b]: hashmap) {
            good_pairs+=(b*(b-1)/2);
        }
        return good_pairs;
    }
};