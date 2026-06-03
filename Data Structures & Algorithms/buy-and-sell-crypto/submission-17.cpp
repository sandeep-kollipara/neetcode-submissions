class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> stk;
        int x2 = 0;
        bool first_drop = false; // indicates that the drop in price is first occurence
        for (int i=1; i<prices.size(); i++){
            int x1 = prices[i-1];
            x2 = prices[i];
            stk.push(x1);
            if (x2 < x1) {
                if (not first_drop) stk.pop();
                first_drop=false; // price has dropped once
            }
            else first_drop = true;
        }
        if (first_drop) stk.push(x2);
        int maximum = -9999;
        int minimum = 9999;
        int delta = 0; // default
        while(not stk.empty()){
            int y = stk.top();
            stk.pop();
            cout << y << " ";
            if (y < minimum) minimum = y;
            else {
                if (maximum - minimum > delta) delta = maximum - minimum;
            }
            if (y > maximum) {
                maximum = y;
                minimum = y;
            }
        }
        if (maximum - minimum > delta) delta = maximum - minimum;
        return delta;
    }
};
