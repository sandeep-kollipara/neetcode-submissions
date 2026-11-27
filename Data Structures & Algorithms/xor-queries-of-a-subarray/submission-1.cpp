class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix_arr(arr.size(), 0), result;
        prefix_arr[0] = arr[0];
        for (int i=1; i<prefix_arr.size(); i++) {
            prefix_arr[i] = prefix_arr[i-1]^arr[i];
        }
        for (auto q: queries) {
            int response = prefix_arr[q[1]];
            if (q[0]>0) response^=prefix_arr[q[0]-1];
            result.push_back(response);
        }
        return result;
    }
};
