class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // n-ary decision tree doesn't work without duplicates
        // using subsets logic with manual duplication
        vector<int> nums2;
        for (int i: nums) {
            int j=0;
            while (j<target/i) {
                nums2.push_back(i);
                j++;
            }
        }
        //cout << nums2.size();
        int tot=0;
        vector<int> nullset;
        vector<vector<int>> combine;
        auto backtrack=[](auto&& self, int i, int sum, int tgt, vector<int>& temp, vector<int>& arr, vector<vector<int>>& combs){
            // base case or termination plus work
            //cout << i << endl;
            if (sum > tgt) return ;
            else if (sum==tgt) {
                cout << i << endl;
                combs.push_back(temp);
                return ;
            }
            if (i==arr.size()) return; // this should be after the update
            // traversal
            //for (int a: arr) {
                //temp.push_back(a);
            temp.push_back(arr[i]);
            //self(self, i+1, sum+a, tgt, temp, arr, combs);
            self(self, i+1, sum+arr[i], tgt, temp, arr, combs);
            temp.pop_back();
            while (i+1<arr.size() and arr[i]==arr[i+1]) i++;
            self(self, i+1, sum, tgt, temp, arr, combs);
            //}
        };
        backtrack(backtrack, 0, tot, target, nullset, nums2, combine);
        return combine;
    }
};
