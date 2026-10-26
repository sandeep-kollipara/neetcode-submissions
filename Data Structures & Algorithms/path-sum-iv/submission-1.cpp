class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> arr(4, vector<int>(8, -1)); // first index - depth, second index - position
        for (int i: nums) {
            int depth = i/100, position = i%100/10, val = i%10;
            arr[depth-1][position-1] = val;
        }
        int total=0;
        auto dfs=[&](auto&& self, int i, int j, int sum){
            // base case or termination
            if ((i<4 and j<8 and arr[i][j]==-1) or i>3 or j>7) return 0;
            // pre-order traversal
            sum+=arr[i][j];
            if (i==3 or (arr[i+1][2*j+1]==-1 and arr[i+1][2*j]==-1)) total+=sum;
            self(self, i+1, 2*j, sum);
            self(self, i+1, 2*j+1, sum);
            return 0;
        };
        dfs(dfs, 0, 0, 0);
        return total;
    }
};
