class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> base={{}}, target;
        for (int i: nums) {
            for (vector<int> sub: base) {
                target.push_back(sub); // without i
                sub.push_back(i);
                target.push_back(sub); // with i
            }
            base = target;
            target = {};
        }
        return base;
    }
};
