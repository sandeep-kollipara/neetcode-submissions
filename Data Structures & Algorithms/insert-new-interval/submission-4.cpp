class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int initial=-1, final=-1;
        for (int i=0; i<intervals.size(); i++) {
            if (newInterval[0]>=intervals[i][0] and newInterval[0]<=intervals[i][1]) {
                initial=i;
                newInterval[0] = intervals[i][0];
            }
            else if (newInterval[0]<intervals[i][0] and i==0) {
                initial=i;
            }
            else if (i>1 and newInterval[0]>intervals[i-1][1] and newInterval[0]<intervals[i][0]) {
                initial=i;
            }
            if (newInterval[1]>=intervals[i][0] and newInterval[1]<=intervals[i][1]) {
                final=i;
                newInterval[1] = intervals[i][1];
            }
            else if (newInterval[1]>intervals[i][1] and i==intervals.size()-1) {
                final=i;
            }
            else if (i<intervals.size()-1 and newInterval[1]>intervals[i][1] and newInterval[1]<intervals[i+1][0]){
                final=i;
            }
        }
        cout << initial << " " << final;
        if (intervals.size()==0) initial=0;
        if (initial>=0 and final>=0) for (int position=final; position>=initial; position--) intervals.erase(intervals.begin()+position);
        if (initial!=-1) intervals.insert(intervals.begin()+initial, newInterval);
        else intervals.insert(intervals.begin()+final+1, newInterval);
        return intervals;
    }
};
