class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        auto isPrefixAndSuffix=[](string a, string b){
            if (a.length() > b.length()) return false;
            size_t prefix_pos = b.find(a, 0);
            /*size_t pos=0, suffix_pos;
            while (pos!=string::npos) {
                suffix_pos = pos;
                pos = b.find(a,pos+1);
            }*/
            size_t suffix_pos = b.find(a, b.length()-a.length());
            //cout << a << " " << b << " " << prefix_pos << " " << suffix_pos;
            return prefix_pos==0 and suffix_pos==b.length()-a.length();
        };
        int pairs=0;
        for (int i=0; i<words.size()-1; i++) {
            for (int j=i+1; j<words.size(); j++) {
                if (isPrefixAndSuffix(words[i],words[j])) pairs++;
            }
        }
        return pairs;
    }
};