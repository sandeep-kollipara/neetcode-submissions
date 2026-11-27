class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> hashset; // INCORRECT
        for (int i: nums) {
            if (not hashset.count(i)) hashset.insert(i);
            else hashset.erase(i);
        }
        vector<int> result;
        for (int i: hashset) result.push_back(i);
        return result;
    }
};