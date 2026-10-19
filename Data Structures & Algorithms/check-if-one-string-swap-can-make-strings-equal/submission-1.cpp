class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> mismatches;
        for (int i=0; i<s1.length(); i++) {
            if (s1[i]!=s2[i]) mismatches.push_back(i);
        }
        return (mismatches.size()==2 
        and s1[mismatches[0]]==s2[mismatches[1]] 
        and s1[mismatches[1]]==s2[mismatches[0]]) 
        or (mismatches.size()==0) ? true: false;
    }
};
