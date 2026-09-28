class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> alphabets(26, 0);
        bool skip;
        int count = 0;
        for (auto& c: allowed) {
            alphabets[(int)c-97]++;
        }
        for (auto& s: words) {
            skip = false;
            //for (auto iter=alphabets.begin(); iter!=alphabets.end(); iter++) {
            //    *iter = 0;
            //}
            for (auto& c: s) {
                if (alphabets[(int)c-97]==0) {
                    skip = true;
                    break;
                }
            }
            if (not skip) count++;
        }
        return count;
    }
};