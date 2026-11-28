class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // make intervals non-overlapping or exclusive
        auto cmp=[](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        };
        sort(meetings.begin(), meetings.end(), cmp);
        int free = meetings[0][0] - 1, last = meetings[0][1];
        for (auto i=meetings.begin()+1; i!=meetings.end(); i++) {
            auto j = i-1;
            if ((*j)[1] >= (*i)[0]) {
                (*i)[0] = (*j)[0];
                (*i)[1] = max((*i)[1], (*j)[1]);
            }
            free+=max(0, (*i)[0] - last-1);
            last = (*i)[1];
        }
        //for (auto v: meetings) cout << v[0] << "," << v[1] << endl;
        return days + free - last;
    }
};
