class Solution {
public:
    int maxTransactions(vector<int>& transactions) {
        int balance=0, skips=0;
        for (int i=0; i<transactions.size(); i++) {
            balance+=transactions[i];
            if (balance < 0) {
                skips++;
                balance-=transactions[i];
            }
        }
        return transactions.size()-skips;
    }
};
