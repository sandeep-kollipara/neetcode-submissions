class Solution {
public:
    bool lemonadeChange(vector<int>& bills) { // greedy method
        vector<int> cashier(3, 0); // [$5, $10, $20]
        for (int i=0; i<bills.size(); i++) {
            // return change
            int change = bills[i];
            if (change-5==5) { // $10
                if (cashier[0]>0) cashier[0]--;
                else return false;
            } else if (change-5==15) { // $20
                if (cashier[1]>0 and cashier[0]>0) {
                    cashier[1]--;
                    cashier[0]--;
                } else if (cashier[0]>2) {
                    cashier[0]-=3;
                } else {
                    return false;
                }
            }
            // update
            if (change==5) cashier[0]++;
            else if (change==10) cashier[1]++;
            else cashier[2]++;
        }
        return true;
    }
};