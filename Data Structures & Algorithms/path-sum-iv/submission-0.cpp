class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> arr(4, vector<int>(8, -1)); // first index - depth, second index - position
        for (int i: nums) {
            int depth = i/100, position = i%100/10, val = i%10;
            arr[depth-1][position-1] = val;
        }
        /*for (auto v: arr){
            for (int i: v) cout << i << " ";
            cout << endl;
        }*/
        auto dfs=[&](auto&& self, int i, int j)->pair<int,int>{
            // base case or termination
            if ((i<4 and j<8 and arr[i][j]==-1) or i>3 or j>7) return {0,0};
            // post-order traversal (independent)
            pair<int,int> left = self(self, i+1, 2*j);
            pair<int,int> right = self(self, i+1, 2*j+1);
            pair<int,int> center;
            if (left.second==0 and right.second==0) center = {arr[i][j],1};
            else center = {left.first+right.first+(left.second+right.second)*arr[i][j], left.second+right.second};
            cout << center.first << "," << center.second << endl;
            return center;
        };
        return dfs(dfs, 0, 0).first;
    }
};
