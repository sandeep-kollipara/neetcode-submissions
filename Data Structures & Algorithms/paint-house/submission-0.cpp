class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // Definition - T[i][j] = min cost of painting all houses from 0 to i 
        // and painting ith house with paint j
        // (costs is our DP table)
        // Base case - i=0 (costs already has the min cost)
        // Recurrence relation - T[i][j] = min(T[i-1][!j]) + costs[i][j]
        for (int i=1; i<costs.size(); i++) {
            for (int j=0; j<costs[0].size(); j++) {
                if (j==0) costs[i][j] += min(costs[i-1][1],costs[i-1][2]);
                else if (j==1) costs[i][j] += min(costs[i-1][0],costs[i-1][2]);
                else costs[i][j] += min(costs[i-1][0],costs[i-1][1]);
            }
        }
        return min(min(costs[costs.size()-1][0], costs[costs.size()-1][1]), costs[costs.size()-1][2]);
    }
};