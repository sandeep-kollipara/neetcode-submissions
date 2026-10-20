class Solution {
public:
    vector<vector<int>> indexPairs(string text,vector<string>& words) {
        vector<vector<int>> res;
        for (string w: words) {
            size_t pos = text.find(w);
            while (pos != string::npos) {
                res.push_back({(int)pos, (int)(pos + w.length() - 1)});
                pos = text.find(w, pos + 1);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
