class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> hashmap, hashmap2;
        bool first=true;
        for (string r: words) {
            hashmap.clear();
            for (char c: r) hashmap[c]++;
            if (not first) for (auto& [a,b]: hashmap2) {
                if (hashmap.find(a)!=hashmap.end()) hashmap2[a] = min(hashmap[a],b);
                else hashmap2[a] = 0;
                //hashmap2[a] = min(b,hashmap2[a]);
            } else hashmap2 = hashmap;
            first = false;
        }
        vector<string> res;
        for (auto& [a,b]: hashmap2) {
            string t;
            t+=a;
            for (int i=0; i<b; i++) res.push_back(t); 
        }
        return res;
    }
};