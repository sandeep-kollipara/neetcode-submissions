class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size()==1 and gas[0]<cost[0]) return -1;
        else if (gas.size()==1) return 0;
        vector<int> difference, del_difference;
        //del_difference.push_back(gas[gas.size()-1]-cost[cost.size()-1]);
        for (int i=0; i<gas.size(); i++) {
            difference.push_back(gas[i]-cost[i]);
            //if (i!=gas.size()-1) del_difference.push_back(gas[i]-cost[i]);
            //del_difference[i] = difference[i] - del_difference[i];
        }
        int j;
        vector<int> possibilities; // valid starting points
        for (int i=0; i</*del_*/difference.size(); i++) {
            if (i==0) j = /*del_*/difference.size()-1;
            else j = i-1;
            if (/*del_*/difference[i]>0 and /*del_*/difference[j]<0) possibilities.push_back(i);
        }
        int net;
        bool valid;
        vector<int> sum;
        for (int i: possibilities) {
            cout << "possibilities: " << i << endl;
            int k=i;
            net=0;
            valid=true;
            sum={};
            while (sum.size()<gas.size()) {
                if (i<gas.size()) net+=difference[i];
                else net+=difference[i-gas.size()];
                if (net<0) valid=false;
                sum.push_back(net);
                i++;
            }
            if (valid==true) return k;
        }
        return -1;
    }
};
