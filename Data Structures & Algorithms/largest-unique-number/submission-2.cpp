class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_set<int> hashset1, hashset2;
        for (auto a: nums) {
            if (hashset1.find(a)!=hashset1.end()) hashset2.insert(a);
            else hashset1.insert(a);
        }
        int maximum=INT_MIN;
        for (auto a: hashset1) {
            if (hashset2.find(a)==hashset2.end()) {
                maximum = (maximum > a) ? maximum : a;
            }
        }
        if (maximum==INT_MIN) return -1;
        return maximum;
    }
};
