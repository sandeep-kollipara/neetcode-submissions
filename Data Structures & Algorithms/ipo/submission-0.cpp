class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> coalesced;
        for (int i=0; i<profits.size(); i++) coalesced.push_back({capital[i], profits[i]});
        auto cmp=[](const pair<int,int> a, const pair<int,int> b){
            if (a.first==b.first) return a.second > b.second;
            return a.first < b.first;
        };
        sort(coalesced.begin(), coalesced.end(), cmp);
        //for (auto i: coalesced) cout << i.first << " ";
        //cout << endl;
        //for (auto i: coalesced) cout << i.second << " ";
        auto cmp2=[](const pair<int,int> a, const pair<int,int> b) {
            return a.second < b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp2)> pq; // max heap
        int i=0;
        while (k>0) {
            while (i< coalesced.size() and coalesced[i].first <= w) {
                pq.push(coalesced[i]);
                i++;
            }
            if (!pq.empty()) {
                w+=pq.top().second;
                pq.pop();
            }
            k--;
        }
        return w;
    }
};