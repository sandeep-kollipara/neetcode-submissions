class Solution {
public:
    int countElements(vector<int>& arr) {
        int count=0;
        unordered_set<int> hashset;
        for (auto a: arr) hashset.insert(a);
        for (auto a: arr) if (hashset.find(a+1)!=hashset.end()) count++;
        return count;
    }
};
