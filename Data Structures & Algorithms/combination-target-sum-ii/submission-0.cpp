class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        auto backtrack=[](auto&& self, int i, int sum, int target, vector<int>& temp, vector<int>& arr, vector<vector<int>>& combs){
            //for (int i: temp) cout << i << " ";
            //cout << endl << "sum: " << sum << endl;
            // base case or termination and work
            if (sum==target) {
                combs.push_back(temp);
                return ;
            } else if (sum>target) {
                return ;
            }
            if (i==arr.size()) return ;
            // traversal
            temp.push_back(arr[i]);
            self(self, i+1, sum+arr[i], target, temp, arr, combs);
            temp.pop_back();
            while (i+1<arr.size() and arr[i]==arr[i+1]) i++;
            self(self, i+1, sum, target, temp, arr, combs);
        };
        vector<vector<int>> combine;
        vector<int> nullset;
        sort(candidates.begin(), candidates.end());
        backtrack(backtrack, 0, 0, target, nullset, candidates, combine);
        return combine;
    }
};
