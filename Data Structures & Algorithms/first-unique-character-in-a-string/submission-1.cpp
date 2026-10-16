class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freqmap(26);
        for (char c: s) freqmap[c-'a']++;
        for (int i=0; i<s.length(); i++) if (freqmap[s[i]-'a']==1) return i;
        return -1;
    }
};