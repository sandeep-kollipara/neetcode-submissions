class Solution {
public:
    vector<vector<int>> indexPairs(string text,vector<string>& words) {
        vector<vector<int>> res;
        for (string w: words) {
            int pos=0;
            while (pos >= 0) {
                pos = text.find(w, pos);
                if (pos>=0) {
                    res.push_back({(int)pos, (int)(pos + w.length() - 1)});
                    pos++;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
