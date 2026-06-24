class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n, 0), nullset;
        //sort(temp.begin(), temp.end());
        for (int i=1; i<=n; i++) nums[i-1] = i;
        vector<vector<int>> combine;
        auto combinations=[](auto&& self, int i, int k, vector<int>& temp, vector<int>& arr, vector<vector<int>>& combs) {
            // base case or termination plus work
            if (temp.size()==k) {
                combs.push_back(temp);
                return ;
            }
            if (i==arr.size()) return ;
            // traversal 
            temp.push_back(arr[i]);
            self(self, i+1, k, temp, arr, combs);
            temp.pop_back();
            while(i+1<arr.size() and arr[i+1]==arr[i]) i++;
            self(self, i+1, k, temp, arr, combs);
        };
        combinations(combinations, 0, k, nullset, nums, combine);
        return combine;
    }
};