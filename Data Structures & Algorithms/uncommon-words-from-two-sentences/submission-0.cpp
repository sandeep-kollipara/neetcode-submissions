class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> hashmap1, hashmap2;
        string temp;
        for (char c: s1) {
            if (c==' '){
                hashmap1[temp]++;
                temp="";
            } else temp+=c;
        }
        hashmap1[temp]++;
        temp="";
        for (char c: s2) {
            if (c==' '){
                hashmap2[temp]++;
                temp="";
            } else temp+=c;
        }
        hashmap2[temp]++;
        vector<string> result;
        for (auto& [a,b]: hashmap1){
            if (hashmap2.find(a)==hashmap2.end() and b==1) result.push_back(a);
        }
        for (auto& [a,b]: hashmap2){
            if (hashmap1.find(a)==hashmap1.end() and b==1) result.push_back(a);
        }
        return result;
    }
};
