class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // calc default satisfied
        int default_sat = 0;
        for (int i=0; i<customers.size(); i++) default_sat+=(customers[i]*abs(grumpy[i]-1)); 
        //cout<< default_sat << endl;
        // calc additional satisfied using sliding window and check for max
        int i=0, j=minutes-1, additional=0, max_addl = 0;
        for (int k=i; k<=j; k++) {
            additional += (customers[k]*grumpy[k]);
        }
        while (j<customers.size()) {
            if (i>0) {
                additional -= (customers[i-1]*grumpy[i-1]);
                additional += (customers[j]*grumpy[j]); 
            }
            max_addl = max(additional, max_addl);
            i++;
            j++;
        }
        //cout << max_addl << endl;
        return default_sat + max_addl;
    }
};