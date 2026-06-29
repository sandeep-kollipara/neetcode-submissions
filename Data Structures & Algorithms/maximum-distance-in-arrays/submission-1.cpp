class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int glob_min=arrays[0][0], glob_max=arrays[0][arrays[0].size()-1], first, last, result = INT_MIN;
        for (int i=1; i<arrays.size(); i++) {
            first = arrays[i][0];
            last = arrays[i][arrays[i].size()-1];
            result = max(result, last - glob_min);
            result = max(result, glob_max - first);
            glob_min = min(glob_min, first);
            glob_max = max(glob_max, last);
        }
        return result;
    }
};
