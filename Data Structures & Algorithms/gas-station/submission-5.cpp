class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size()==1 and gas[0]<cost[0]) return -1;
        else if (gas.size()==1) return 0;
        vector<int> difference, sum_difference;
        for (int i=0; i<gas.size(); i++) {
            difference.push_back(gas[i]-cost[i]);
            if (sum_difference.size()==0) sum_difference=difference;
            else sum_difference.push_back(sum_difference[i-1]+difference[i]);
        }
        int min_sum = sum_difference[0], min_idx=0;
        for (int i=1; i<gas.size(); i++) {
            if (sum_difference[i] < min_sum) {
                min_sum = sum_difference[i];
                min_idx = i;
            }
        }
        min_idx++;
        if (min_idx==gas.size()) min_idx=0; 
        int net=0;
        bool valid=true;
        vector<int> sum;
        int i=min_idx;
        while (sum.size()<gas.size()) {
            if (i<gas.size()) net+=difference[i];
            else net+=difference[i-gas.size()];
            if (net<0) valid=false;
            sum.push_back(net);
            i++;
        }
        if (valid==true) return min_idx;
        return -1;
    }
};
