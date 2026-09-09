class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> hashmap;
        unordered_map<string, char> hashmap2;
        vector<string> str;
        int j=0;
        for (int i=0; i<s.length(); i++) {
            if (s[i]==' ') {
                str.push_back(s.substr(j,i-j));
                j=i+1;
            }
        }
        str.push_back(s.substr(j,s.length()-j));
        if (str.size()!=pattern.length()) return false;
        for (int i=0; i<pattern.size(); i++) {
            char c = pattern[i];
            string v = str[i];
            cout << c << ":" << v << endl;
            // add to hashmap
            if (hashmap.find(c)==hashmap.end()) hashmap[c] = v;
            // check if existing is same as the matching
            else if (hashmap[c] == v) ;
            // otherwise no match
            else return false;
            // add to hashmap2
            if (hashmap2.find(v)==hashmap2.end()) hashmap2[v] = c;
            // check if existing is same as the matching
            else if (hashmap2[v] == c) ;
            // otherwise no match
            else return false;
        }
        return true;
    }
};