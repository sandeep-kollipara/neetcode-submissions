class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto eating_time=[&](int r){
            if (r == 0) return (long long)2e18; // Prevent division by zero
            long long time = 0;
            for (int i: piles) {
                time += (i + r - 1LL) / r;
            }
            return time;
        };
        int max_time = h;
        int best_ans = *max_element(piles.begin(), piles.end());
        int l=1, m=l+(h-l)/2;
        h=best_ans;
        while (l<=h) {
            if (eating_time(m) > max_time) l = m+1;
            else if (eating_time(m) <= max_time) h = m-1;
            //else return m;
            m = l+(h-l)/2;
        }
        while(eating_time(h)<= max_time){
            h--;
        }
        return l;
        //return h+1;
    }
};
