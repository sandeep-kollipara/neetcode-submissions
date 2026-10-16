class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> hashmap;
        s1 = s1 + ' ' + s2;
        string temp;
        for (char c: s1) {
            if (c!=' ') temp+=c;
            else {
                hashmap[temp]++;
                temp="";
            }
        }
        hashmap[temp]++;
        vector<string> result;
        for (auto& [a,b]: hashmap) {
            if (b==1) result.push_back(a);
        }
        return result;
    }
};
