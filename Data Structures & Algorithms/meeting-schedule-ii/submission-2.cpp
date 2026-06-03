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
    int minMeetingRooms(vector<Interval>& intervals) { // earliest start time first
        if (intervals.size()==0) return 0; // edge case
        function<bool(Interval,Interval)> customComparator=[](Interval a, Interval b) {
            return a.start < b.start; // sorts in ascending order
        };
        sort(intervals.begin(), intervals.end(), customComparator);
        for (Interval i: intervals) cout << "(" << i.start << "," << i.end << ") ";
        cout << endl;
        stack<Interval> day;
        int i=0, num_of_days=0;
        while (!intervals.empty()) {
            if (day.empty()) { // stack is empty, i doesn't update
                day.push(intervals[i]);
                intervals.erase(intervals.begin()+i);
            }
            else { // stack is not empty
                Interval current = intervals[i];
                Interval previous = day.top();
                if (current.start >= previous.end) { // can add, i doesn't update
                    day.push(current);
                    intervals.erase(intervals.begin()+i);
                }
                else { // can't add, i updates
                    i++;
                }
            }
            if (i==intervals.size()) { // end of the day, clear stack and reset i
                i=0;
                stack<Interval> empty;
                cout << day.size() << "," << intervals.size() << endl;
                day.swap(empty);
                num_of_days++;
            }
        }
        return num_of_days;
    }
};
