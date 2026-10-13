class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto cmp=[](pair<int,int> a, pair<int,int> b){
            return a.first < b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> maxheap(cmp);
        unordered_map<int,int> hashmap;
        for (auto i: nums) hashmap[i]++;
        for (auto& [a,b]: hashmap){
            maxheap.push({b, a});
        }
        vector<int> top_k(k);
        for (int i=0; i<k; i++) {
            top_k[i]=maxheap.top().second;
            maxheap.pop();
        }
        return top_k;
    }
};
