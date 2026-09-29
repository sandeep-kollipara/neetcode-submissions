class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int bitmask = 0, neuva, count=0;
        for (char c: allowed) {
            neuva = 1 << ((int)c - 97);
            bitmask |= neuva;
        }
        //cout << bitset<64>(bitmask) << endl;
        bool skip;
        for (string s: words) {
            //cout << s << endl;
            skip = false;
            for (char c: s) {
                neuva = bitmask >> ((int)c - 97);
                //cout << ((neuva) & 1) << endl;
                if (((neuva) & 1) == 0) {
                    skip = true;
                    break;
                }
            }
            if (not skip) count++;
        }
        return count;
    }
};