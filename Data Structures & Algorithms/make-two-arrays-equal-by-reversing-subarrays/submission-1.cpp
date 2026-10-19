class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> hashmap;
        for (int i: target) hashmap[i]++;
        for (int i: arr) hashmap[i]--;
        int discrepancy=0;
        for (auto& [a, b]: hashmap) if (b!=0) discrepancy++;
        return discrepancy==0;
    }
};
