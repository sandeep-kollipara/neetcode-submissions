class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        for (auto q: queries) {
            int x=0;
            for (int i=q[0]; i<=q[1]; i++) {
                x^=arr[i];
            }
            result.push_back(x);
        }
        return result;
    }
};
