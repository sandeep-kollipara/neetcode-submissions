class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp=[](pair<int,int> i, pair<int,int> j) {
            if (i.first!=j.first) return i.first > j.first;
            else return i.second > j.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp); // min heap
        for (int i: arr) pq.push({abs(x-i), i});
        vector<int> out;
        for (int i=0; i<k; i++) {
            out.push_back(pq.top().second);
            pq.pop();
        }
        sort(out.begin(), out.end());
        return out;
    }
};