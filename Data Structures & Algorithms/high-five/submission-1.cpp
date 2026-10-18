class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        auto cmp=[&](int a, int b) {
            if (items[a][0]==items[b][0]) return items[a][1] < items[b][1];
            return items[a][0] > items[b][0];
        };
        priority_queue<int,vector<int>,decltype(cmp)> maxheap(cmp);
        for (int i=0; i<items.size(); i++) maxheap.push(i);
        vector<vector<int>> res;
        int avg;
        while (maxheap.size()) {
            int cur_student=items[maxheap.top()][0];
            avg=0;
            for (int i=0; i<5; i++) {
                avg+=items[maxheap.top()][1];
                maxheap.pop();
            }
            avg/=5;
            res.push_back({cur_student,avg});
            while(maxheap.size() and items[maxheap.top()][0]==cur_student) maxheap.pop();
        }
        return res;
    }
};
