class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> hashmap;
        string r;
        for (char c: s) {
            hashmap[c]++;
        }
        for (auto c: order) {
            while (hashmap[c]) {
                hashmap[c]--;
                r+=c;
            }
        }
        for (auto c: s) {
            while (hashmap[c]) {
                hashmap[c]--;
                r+=c;
            }
        }
        return r;
    }
};