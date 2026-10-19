class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        pair<int,int> min1={INT_MAX,-1}, min2={INT_MAX,-1};
        for (int i=0; i<prices.size(); i++) {
            if (min1.first > prices[i]) {
                min1.first = prices[i];
                min1.second = i;
            }
        }
        for (int i=0; i<prices.size(); i++) {
            if (i!=min1.second and min2.first > prices[i]) {
                min2.first = prices[i];
                min2.second = i;
            }
        }
        return (min1.first + min2.first <= money) ? money - min1.first - min2.first : money;
    }
};