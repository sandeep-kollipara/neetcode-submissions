class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size()!=sentence2.size()) return false;
        unordered_map<string,unordered_set<string>> hashmap;
        for (auto i: similarPairs) {
            hashmap[i[0]].insert(i[1]);
            hashmap[i[1]].insert(i[0]);
        }
        for (int i=0; i<sentence1.size(); i++) {
            if(hashmap[sentence1[i]].find(sentence2[i])==hashmap[sentence1[i]].end() 
            and sentence1[i]!=sentence2[i]) return false;
        }
        return true;
    }
};
