class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> hashmap;
        int total=0;
        bool skip;
        for (auto s: words) {
            skip = false;
            hashmap.clear();
            for (auto c: chars) {
                hashmap[c]++;
            }
            for (auto c: s) {
                if (hashmap.find(c)==hashmap.end()){
                    skip=true;
                    break;
                }
                hashmap[c]--;
                if (hashmap[c]<0) {
                    skip=true;
                    break;
                }
            }
            if (not skip) total+=s.length();
        }
        return total;
    }
};