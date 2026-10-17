class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> buckets(nums.size());
        for (int i: nums) {
            if (i>=buckets.size()) {
                buckets[buckets.size()-1]++;
            } else if (i<buckets.size() and i>0) {
                buckets[i-1]++;
            }
        }
        for (int i=buckets.size()-2; i>-1; i--) buckets[i]+=buckets[i+1];
        for (int i: buckets) cout << i << " ";
        for (int i=0; i<buckets.size(); i++) if (i+1==buckets[i]) return i+1;
        return -1;
    }
};