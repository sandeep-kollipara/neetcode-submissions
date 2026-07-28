class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        auto is_a_match=[](string a, string b, int i) {
            int j=0;
            while (j<a.length() and a[j]==b[i]) {
                i++;
                j++;
            }
            if (j==a.length()) return true;
            return false;
        };
        auto is_a_substr=[&](string a, string b) {
            if (b.length()<a.length()) return false;
            int i=0;
            while (i<b.length()-a.length()+1) {
                if (is_a_match(a,b,i)) return true;
                i++;
            }
            return false;
        };
        //cout << is_a_substr("abd","abcde");
        auto cmp=[](string a, string b){
            return a.size() < b.size();
        };
        sort(words.begin(), words.end(), cmp);
        vector<string> result;
        for (int i=0; i<words.size(); i++) {
            for (int j=i+1; j<words.size(); j++) {
                if (is_a_substr(words[i], words[j])) {
                    result.push_back(words[i]);
                    break;
                } 
            }
        }
        return result;
    }
};