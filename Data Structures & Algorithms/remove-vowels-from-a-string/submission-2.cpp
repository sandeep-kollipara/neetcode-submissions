class Solution {
public:
    string removeVowels(string s) {
        string r;
        /*for (auto i=s.begin(); i!=s.end(); ++i){
            if (*i=='a' 
            or *i=='e'
            or *i=='i'
            or *i=='o'
            or *i=='u') ;//*i='#';
            else r+=*i; 
        }*/
        for (char c: s) {
            if (string("aeiou").find(c)==string::npos) r+=c;
        }
        /*for (char c: s) {
            if (c!='#') r+=c;
        }*/
        return r;
    }
};
