class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Find maximum and total number of positives
        int maximum=INT_MIN, total=0;
        for (auto i: nums) {
            maximum = max(maximum, i);
            if (i>0) total++;
        }
        // edge case: maximum is negative or 0 or total is zero
        if (total==0) return 1;
        // cycle through the 1 through total and return the lowest num absent
        bool skip;
        for (int i=1; i<total+1; i++) {
            skip=true;
            for (auto j: nums) {
                if (i==j) {
                    skip=false;
                    break;
                }
            }
            if (skip) return i;
        }
        return total+1;
    }
};