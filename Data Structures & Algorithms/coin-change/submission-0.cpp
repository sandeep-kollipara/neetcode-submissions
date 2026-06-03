class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // define T[i] = minimum num of coins required for change i
        vector<int> T(amount+1);
        // base case
        T[0] = 0;
        // recurrence relation
        if (amount > 0) for (int i=1; i<amount+1; i++){
            int j=i-1, copies=10001, j_min=-1;
            while(j>-1){
                if (T[j]!=-1) {
                    int change = i-j;
                    for(int k=coins.size()-1; k>-1; k--){
                        int coin = coins[k];
                        if (change%coin==0 and (copies > T[j] + change/coin)) { // preserving minimum
                            j_min = j;
                            copies = T[j] + change/coin;
                        }
                    }
                }
                j--;
            }
            if (copies < 10001) T[i] = copies;
            else T[i] = -1;
        }
        return T[amount];
    }
};
