class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) { // O(1000*trips.size())
        vector<int> path(1001, 0);
        for (vector<int> trip: trips) {
            for (int i=trip[1]; i<trip[2]; i++) path[i]+=trip[0];
        }
        int max_pool = *max_element(path.begin(), path.end());
        cout << max_pool;
        if (max_pool > capacity) return false;
        else return true;
    }
};