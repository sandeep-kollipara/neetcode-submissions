class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // define T[i] = max profit from selling on (i+1)th day
        vector<int> T(prices.size()+1);
        vector<int> max_T(prices.size()+1);
        // base cases
        T[0] = 0;
        T[1] = 0;
        T[2] = max(0,prices[1]-prices[0]);
        max_T[2] = max(0,T[2]);
        // recurrence relation - T[i] = max(max(T[0],T[i-j-1])+prices[i-1]-prices[i-j-1]) (for j=2 to j=i-1)
        if (prices.size()>2) for (int i=3; i<T.size(); i++) {
            for (int j=1; j<i; j++) {
                T[i] = max(max_T[i-j-2]+prices[i-1]-prices[i-j-1], T[i]);
            }
            max_T[i] = max(max_T[i-1],T[i]);
        }
        return *max_element(T.begin(), T.end());
    }
};
