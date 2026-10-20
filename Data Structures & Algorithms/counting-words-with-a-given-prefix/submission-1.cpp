class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for (string w: words) {
            if (pref.length()<=w.length() and w.find(pref,0)==0) count++;
        }
        return count;
    }
};