class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // make intervals non-overlapping or exclusive
        auto cmp=[](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        };
        sort(meetings.begin(), meetings.end(), cmp);
        vector<vector<int>> exclusive;
        exclusive.push_back(meetings[0]);
        for (auto i=meetings.begin()+1; i!=meetings.end(); i++) {
            auto j = i-1;
            if ((*j)[1] >= (*i)[0]) {
                (*i)[0] = (*j)[0];
                (*i)[1] = max((*i)[1], (*j)[1]);
                exclusive.pop_back();
            }
            exclusive.push_back(*i);
        }
        //for (auto v: exclusive) cout << v[0] << "," << v[1] << endl;
        // remove the exclusive ranges directly from days
        for (auto v: exclusive) days-=(v[1]-v[0]+1);
        return days;
    }
};
