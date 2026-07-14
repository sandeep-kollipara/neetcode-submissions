class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size()!=sentence2.size()) return false;
        unordered_map<string,vector<string>> hashmap;
        for (auto i: similarPairs) {
            hashmap[i[0]].push_back(i[1]);
            hashmap[i[1]].push_back(i[0]);
        }
        for (int i=0; i<sentence1.size(); i++) {
            if(find(hashmap[sentence1[i]].begin(),hashmap[sentence1[i]].end(),sentence2[i])==hashmap[sentence1[i]].end()
            and sentence1[i]!=sentence2[i]) return false;
        }
        return true;
    }
};
