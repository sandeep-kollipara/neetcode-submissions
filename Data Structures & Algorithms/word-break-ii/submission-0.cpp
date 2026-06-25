class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // add dictionary words to a hashset for quick verification
        unordered_set<string> hashset;
        for (string a: wordDict) hashset.insert(a);
        // use modified backtracking algo to check all possibilities through decision tree
        auto backtrack=[&](auto&& self, int start, int curr, vector<string>& temp, string s, vector<vector<string>>& combs){
            // base case or termination plus work
            if (start==s.length() and curr==s.length()) {
                combs.push_back(temp);
                return ;
            } else if (curr==s.length()) return ;
            // traversal
            while(curr<s.length() and hashset.find(s.substr(start,curr-start+1))==hashset.end()) curr++;
            if (curr==s.length()) return;
            temp.push_back(s.substr(start,curr-start+1));
            //cout << temp[temp.size()-1] << endl;
            self(self, curr+1, curr+1, temp, s, combs);
            temp.pop_back();
            self(self, start, curr+1, temp, s, combs);
        };
        vector<string> nullset;
        vector<vector<string>> combine;
        backtrack(backtrack, 0, 0, nullset, s, combine);
        //cout << combine.size() << endl;
        vector<string> result;
        for (auto a: combine) {
            string t;
            for (auto b: a) {
                if (t!="") t+=' ';
                t+=b;
            }
            result.push_back(t);
        }
        return result;
    }
};