class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for (int i: nums) hashmap[i]++;
        vector<pair<int,int>> arr;
        for (auto& [a,b]: hashmap) {
            arr.push_back({a,b});
        }
        auto cmp=[](pair<int,int> a, pair<int,int> b){
            if (a.second==b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        };
        sort(arr.begin(),arr.end(),cmp);
        vector<int> res;
        for (pair<int,int> i: arr) for(int j=0; j<i.second; j++) res.push_back(i.first);
        return res;
    }
};