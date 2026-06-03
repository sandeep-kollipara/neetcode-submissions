class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        function<vector<vector<int>>(vector<int>, vector<vector<int>>)> recurse=[&](vector<int> arr, vector<vector<int>> permutations) {
            // termination
            if (permutations[0].size()==arr.size()) return permutations;
            // 
            vector<vector<int>> extended;
            for (vector<int> p: permutations) {
                vector<int> temp = arr;
                for (int i: p) temp.erase(find(temp.begin(),temp.end(),i));
                for (int i: temp) {
                    vector<int> v = p;
                    v.push_back(i);
                    extended.push_back(v);
                }
            }
            return recurse(arr, extended);
        };
        return recurse(nums, vector<vector<int>>({{}}));
    }
};
