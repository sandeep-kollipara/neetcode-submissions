class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> aeiou(words.size(), 0);
        int i=0;
        for (auto s: words) {
            if (s.length() 
            and (s[0]=='a' or s[0]=='e' or s[0]=='i' or s[0]=='o' or s[0]=='u')
            and (s[s.length()-1]=='a' or s[s.length()-1]=='e' or 
            s[s.length()-1]=='i' or s[s.length()-1]=='o' or 
            s[s.length()-1]=='u')) aeiou[i]++;
            i++;
        }
        for (int i=1; i<aeiou.size(); i++) aeiou[i] = aeiou[i] + aeiou[i-1];
        //for (auto a: aeiou) cout << a << " ";
        vector<int> result(queries.size());
        i=0;
        for (auto v: queries) {
            if (v[0]) result[i] = aeiou[v[1]] - aeiou[v[0]-1];
            else result[i] = aeiou[v[1]];
            i++;
        }
        return result;
    }
};