class Solution {
public:
    int findLucky(vector<int>& arr) {
        int lucky=-1;
        unordered_map<int,int> hashmap;
        for (auto& i: arr) hashmap[i]++;
        for (auto& [a,b]: hashmap) {
            if (a==b) lucky = max(a,lucky);
        }
        return lucky;
    }
};