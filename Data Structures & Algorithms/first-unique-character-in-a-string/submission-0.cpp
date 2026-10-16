class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hashmap;
        for (char c: s) hashmap[c]++;
        for (int i=0; i<s.length(); i++) {
            if (hashmap[s[i]]==1) return i;
        }
        return -1;
    }
};