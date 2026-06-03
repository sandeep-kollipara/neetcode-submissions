/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        auto comparator=[](Interval a, Interval b) {
            return (a.start < b.start);
        };
        sort(intervals.begin(), intervals.end(), comparator); // nlogn
        int all_end = 0;
        for (auto i: intervals) {
            if (i.start >= all_end and i.end > all_end) all_end = i.end;
            else return false;
            cout << all_end << endl;
        }
        return true;
    }
};
