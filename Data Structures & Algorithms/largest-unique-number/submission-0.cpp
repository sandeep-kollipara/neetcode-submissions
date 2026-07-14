class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        auto cmp=[](const pair<int,int> a, const pair<int,int> b){
            if (a.first==b.first) return a.second < b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        unordered_map<int,int> hashmap;
        for (auto a: nums) hashmap[a]++;
        for (auto [a,b]: hashmap) {
            pq.push(make_pair(b,a));
        }
        if (pq.top().first==1) return pq.top().second;
        return -1;
    }
};
