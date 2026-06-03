class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Reverse dynamic programming
        // define T[i] = num of days of colder temperature after ith day
        vector<int> T(temperatures.size());
        // base case
        T[temperatures.size()-1] = 0;
        // recurrence relation - T[i] = (if temp[i]<temp[i+1]) 0 (else) iterate until find 
        if (temperatures.size()>1) for (int i=temperatures.size()-2; i>-1; i--) {
            if (temperatures[i]<temperatures[i+1]) T[i] = 1; // definition
            else {
                T[i] = 0; // default
                for (int j=i+T[i+1]; j<temperatures.size(); j++) {
                    if (temperatures[j]>temperatures[i]) {
                        T[i] = j-i;
                        break;
                    }
                }
            }
        }
        return T;
    }
};
