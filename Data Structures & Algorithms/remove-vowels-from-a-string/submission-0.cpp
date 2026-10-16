class Solution {
public:
    string removeVowels(string s) {
        for (auto i=s.begin(); i!=s.end(); ++i){
            if (*i=='a' 
            or *i=='e'
            or *i=='i'
            or *i=='o'
            or *i=='u') *i='#'; 
        }
        string r;
        for (char c: s) {
            if (c!='#') r+=c;
        }
        return r;
    }
};
