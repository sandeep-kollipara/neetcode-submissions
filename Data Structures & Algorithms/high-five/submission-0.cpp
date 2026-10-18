class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        auto cmp=[](pair<int,int> a, pair<int,int> b) {
            if (a.first==b.first) return a.second < b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> maxheap(cmp);
        for (auto& v: items) maxheap.push({v[0],v[1]});
        vector<vector<int>> res;
        int avg;
        while (maxheap.size()) {
            int cur_student=maxheap.top().first;
            avg=0;
            for (int i=0; i<5; i++) {
                avg+=maxheap.top().second;
                maxheap.pop();
            }
            avg/=5;
            res.push_back({cur_student,avg});
            while(maxheap.size() and maxheap.top().first==cur_student) maxheap.pop();
        }
        return res;
    }
};
