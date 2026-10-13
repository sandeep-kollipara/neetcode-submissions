class Solution {
public:
    bool makeEqual(vector<string>& words) {
        //int total=0;
        //for (auto s: words) total+=s.length();
        //return not (total % words.size());
        unordered_set<char> hashset;
        //vector<unordered_map<char,int>> v_hashmap(words.size());
        unordered_map<char,int> v_hashmap;
        for (int i=0; i<words.size(); i++) {
            for (auto c: words[i]) {
                hashset.insert(c);
                //v_hashmap[i][c]++;
                v_hashmap[c]++;
            }
        }
        bool result=true;
        for (auto c: hashset) {
            int total=0;
            //for (int i=0; i<words.size(); i++) {
            //    total+=v_hashmap[i][c];
            //}
            total = v_hashmap[c];
            result&=(~(bool)(total % words.size()));
        }
        return result;
    }
};