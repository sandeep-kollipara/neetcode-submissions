class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0, i=0;
        while (tickets[k]){
            if (tickets[i]) {
                tickets[i]--;
                time++;
            }
            i++;
            i=i%tickets.size();
        }
        return time;
    }
};