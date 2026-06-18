class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        auto decode_str=[](string s) {
            string t;
            int base = -1;
            for (char c: s) {
                if (base == -1) {
                    base = (int) c;
                    t = "a";
                } else {
                    if ((int)c - base > 0) t += (char)((int)c - base);
                    else t += (char)((int)c - base + 26);
                }
            }
            return t;
        };
        unordered_map<string,vector<string>> hashmap;
        for (string r: strings) hashmap[decode_str(r)].push_back(r);
        vector<vector<string>> result;
        for (const auto& [r, vec]: hashmap) result.push_back(vec);
        return result;
    }
};
