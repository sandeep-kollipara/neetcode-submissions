class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // min possible is sum(piles)/h and max possible is max(piles)
        int min_possible = max(1, (int)floor(accumulate(piles.begin(), piles.end(), 0)/h));
        int max_possible = *max_element(piles.begin(), piles.end());
        cout << min_possible << endl << max_possible << endl;
        function<bool(int)> testing_k=[&](int k) {
            //vector<int>& copy = piles; // soft copy is incorrrect
            vector<int> copy = piles;
            int t = 0;
            //while(!copy.empty()) {
            //    copy[0] -= k;
            //    if (copy[0]<=0) copy.erase(copy.begin());
            //    t++;
            //}
            while(!copy.empty()) {
                int multiplier = 1;
                if (copy[0]>k) multiplier = ceil(copy[0]/k);
                copy[0] -= (k*multiplier);
                if (copy[0]<=0) copy.erase(copy.begin());
                t+=multiplier;
            }
            return (t <= h);
        };
        //for(int i=min_possible; i<=max_possible; i++) if (testing_k(i)) return i;
        int low=min_possible, high=max_possible, mid;
        while (high-low>1) {
            mid = ceil((low+high)/2);
            if (testing_k(mid)) high = mid;
            else low = mid;
        }
        if (testing_k(low)) return low;
        else return high;
    }
};
