class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int tickets_sold=0;
        // calculating tickets sold until k
        for (int i=0; i<=k; i++) {
            //tickets[i]--;
            if (tickets[i]<tickets[k]) tickets_sold+=tickets[i];
            else tickets_sold+=tickets[k];
        }
        // calculating tickets sold after k
        for (int i=k+1; i<tickets.size(); i++) {
            if (tickets[i]<tickets[k]-1) tickets_sold+=tickets[i];
            else tickets_sold+=(tickets[k]-1);
        }
        return tickets_sold;
    }
};