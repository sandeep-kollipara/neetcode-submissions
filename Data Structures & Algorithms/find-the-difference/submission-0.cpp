class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> alphabets(26);
        for(char c: s) alphabets[c-'a']++;
        for(char c: t) alphabets[c-'a']--;
        for(int i=0; i<alphabets.size(); i++) if (alphabets[i]<0) return 'a'+i;
        return 'a';
    }
};