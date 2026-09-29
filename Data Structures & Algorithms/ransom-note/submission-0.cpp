class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hashmap;
        for (char c: magazine) {
            hashmap[c]++;
        }
        for (char c: ransomNote) {
            hashmap[c]--;
            if (hashmap[c]<0) return false;
        }
        return true;
    }
};