class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // O(nlogn)
        int i=1;
        while (i < intervals.size()) {
            if (intervals[i][0]<=intervals[i-1][1]) { // overlap occurs between current and previous
                intervals[i-1][1] = max(intervals[i-1][1], intervals[i][1]);
                intervals.erase(intervals.begin()+i);
                continue;
            }
            i++;
        }
        return intervals;
    }
};
