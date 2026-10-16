class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for (int i: nums) hashmap[i]++;
        auto cmp=[&](int a, int b){
            if (hashmap[a]==hashmap[b]) {
                return a > b;
            }
            return hashmap[a] < hashmap[b];
        };
        sort(nums.begin(),nums.end(),cmp);
        vector<int> res;
        for (int i: nums) res.push_back(i);
        return res;
    }
};