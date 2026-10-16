class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<int,int> hashmap;
        int max_dist=-1;
        for (int i=0; i<s.length(); i++) {
            if (hashmap.find(s[i])!=hashmap.end()) {
                max_dist = max(i-hashmap[s[i]]-1, max_dist);
            }
            else hashmap[s[i]] = i;
        }
        return max_dist;
    }
};