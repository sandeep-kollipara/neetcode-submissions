class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for (int i: nums) hashmap[i]++;
        auto cmp=[](pair<int,int> a, pair<int,int> b){
            if (a.second==b.second) {
                return a.first < b.first;
            } else return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minheap(cmp);
        for (auto& [a,b]: hashmap) {
            minheap.push({a,b});
        }
        vector<int> res;
        while(minheap.size()) {
            for (int i=0; i<minheap.top().second; i++) res.push_back(minheap.top().first);
            minheap.pop();
        }
        return res;
    }
};