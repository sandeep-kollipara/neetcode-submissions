class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        auto backtrack=[](auto&& self, int i, vector<int>& temp, vector<int>& arr, vector<vector<int>>& subsets){
            // base case: work and termination at leaves
            if (i==arr.size()) {
                subsets.push_back(temp);
                return ;
            }
            // traversal
            temp.push_back(arr[i]);
            self(self, i+1, temp, arr, subsets);
            temp.pop_back();
            while (i+1<arr.size() and arr[i+1]==arr[i]) i++; 
            self(self, i+1, temp, arr, subsets);
        };
        vector<int> nullset;
        vector<vector<int>> subs;
        sort(nums.begin(), nums.end());
        backtrack(backtrack, 0, nullset, nums, subs);
        return subs;
    }
};
