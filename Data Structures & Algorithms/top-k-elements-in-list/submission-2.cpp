class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size()+1);
        unordered_map<int,int> hashmap;
        for (auto i: nums){
            hashmap[i]++;
        }
        for (auto& [a, b]: hashmap) {
            buckets[b].push_back(a);
        }
        vector<int> result;
        for (int i=buckets.size()-1; i>-1; i--) {
            for (int j: buckets[i]) {
                result.push_back(j);
                if (result.size()==k) return result;
            }
        }
        return result;
    }
};
