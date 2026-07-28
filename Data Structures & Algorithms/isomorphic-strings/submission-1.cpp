class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length()!=t.length()) return false;
        unordered_map<char,char> hashmap1, hashmap2;
        for (int i=0; i<s.length(); i++) {
            if (hashmap1.find(s[i])==hashmap1.end() and hashmap2.find(t[i])==hashmap2.end()) {
                hashmap1[s[i]]=t[i];
                hashmap2[t[i]]=s[i];
            } else {
                if (hashmap1[s[i]]!=t[i] or hashmap2[t[i]]!=s[i]) return false;
            }
        }
        return true;
    }
};