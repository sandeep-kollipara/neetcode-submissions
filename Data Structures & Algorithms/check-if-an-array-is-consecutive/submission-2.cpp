class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        long total=0;
        int minimum=INT_MAX;
        for (int i: nums) {
            // calculate total
            total+=i;
            // find minimum
            minimum = min(minimum, i);
        }
        //cout << minimum;
        long m=minimum+nums.size()-1, n=minimum-1;
        return total==(m*(m+1)/2-n*(n+1)/2);
    }
};
