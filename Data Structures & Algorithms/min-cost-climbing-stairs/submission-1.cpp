class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // define T[i] = min cost to reach the floor
        vector<int> T(cost.size()+1);
        // base cases
        T[0] = 0;
        T[1] = 0;
        // recurrence relation - T[i] = min(T[i-1]+cost[i-1], T[i-2]+cost[i-2])
        if (cost.size()>1) for (int i=2; i<T.size(); i++){
            T[i] = min(T[i-1]+cost[i-1],T[i-2]+cost[i-2]);
        }
        return T[T.size()-1];
    }
};
