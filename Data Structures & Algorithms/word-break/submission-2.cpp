class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash_set = {};
        for (string s: wordDict) hash_set.insert(s);
        // define T[i] = validity (bool) of the string until the ith position from start
        vector<bool> T(s.length()+1);
        // base case - serves as termination
        T[0] = true;
        // recurrence relation
        if (s.length()>0) for (int i=1; i<s.length()+1; i++) {
            int j = i;
            while(j-->0) if (T[j] and (hash_set.find(s.substr(j, i-j))!=hash_set.end())) break;
            T[i] = (j!=-1);
        }
        for(int i=0; i<T.size(); i++) cout << T[i] << " ";
        return T[s.length()];
    }
};
