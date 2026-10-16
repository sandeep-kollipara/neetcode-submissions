class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>> arr;
        for (int i=0; i<names.size(); i++) arr.push_back({names[i],heights[i]});
        auto cmp=[](pair<string,int> a, pair<string,int> b){
            return a.second > b.second;
        };
        sort(arr.begin(), arr.end(), cmp);
        vector<string> res;
        for (auto i: arr) res.push_back(i.first);
        return res;
    }
};