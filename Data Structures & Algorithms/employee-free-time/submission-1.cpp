/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        // start with a finite min-max interval
        int minimum=INT_MAX, maximum=INT_MIN;
        for (auto& sc: schedule) {
            for (Interval i: sc) {
                minimum = min(i.start, minimum);
                maximum = max(i.end, maximum);
            }
        }
        vector<Interval> result, new_result;
        result.push_back(Interval(minimum, maximum));
        // cycle through all employees and remove their work times
        for (auto& sc: schedule) {
            for (Interval i: sc) {
                new_result = {};
                for (auto j: result) {
                    //cout << i.start << "," << i.end << endl;
                    //cout << j.start << "," << j.end << endl;
                    // 1 of 5 cases: embedded
                    if (i.start <= j.start and j.end <= i.end) {
                        ; // skip this interval
                        //cout << "Case 1" << endl;
                    }
                    // 2 of 5 cases: pre-start
                    else if (i.start > j.start and i.end >= j.end and i.start<j.end) {
                        /*if (i.start > j.start) */new_result.push_back(Interval(j.start, i.start)); // add the remaining
                        //cout << "Case 2" << endl;
                    }
                    // 3 of 5 cases: post-end
                    else if (i.start <= j.start and j.end > i.end and j.start<i.end) {
                        /*if (j.end > i.end) */new_result.push_back(Interval(i.end, j.end)); // add the remaining
                        //cout << "Case 3" << endl;
                    }
                    // 4 of 5 cases: full overlap
                    else if (i.start >= j.start and j.end >= i.end) {
                        if (i.start > j.start) new_result.push_back(Interval(j.start, i.start));
                        if (j.end > i.end) new_result.push_back(Interval(i.end, j.end));
                        //cout << "Case 4" << endl;
                    }
                    // 5 of 5 cases: no overlap
                    else {
                        new_result.push_back(j); // add full interval
                        //cout << "Case 5" << endl;
                    }
                }
                result = new_result;
            }
        }
        // return the remaining intervals
        return result;
    }
};
