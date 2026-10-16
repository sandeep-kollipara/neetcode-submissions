class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_set<string> hashset;
        unordered_map<string,int> hashmap;
        for (string s: words) {
            hashset.clear();
            for (char c: s) {
                string r;
                int i=2;
                r+=c;
                while (hashset.find(r)!=hashset.end()) {
                    r+=to_string(i);
                    i++;
                }
                hashset.insert(r);
            }
            for (string t: hashset) hashmap[t]++;
        }
        vector<string> res;
        for (auto& [a, b]: hashmap) {
            string t;
            t+=a[0];
            if (b==words.size()) res.push_back(t);
        }
        return res;
    }
};