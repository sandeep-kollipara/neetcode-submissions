class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        auto test_load=[&](int load){
            int leftover=load, time=0;
            for (auto i: weights) {
                leftover-=i;
                if (leftover<0) {
                    time++;
                    leftover=load;
                    leftover-=i;
                }
                if (leftover<0) return INT_MAX;
            }
            if (leftover > 0) time++;
            return time;
        };
        int max_w=accumulate(weights.begin(), weights.end(), 0), l=max_w/days, r=max_w, m=l+(r-l)/2;
        while (l<=r) {
            if (test_load(m) <= days) r=m-1;
            else if (test_load(m) > days) l=m+1;
            m = l+(r-l)/2;
        }
        return m;
    }
};