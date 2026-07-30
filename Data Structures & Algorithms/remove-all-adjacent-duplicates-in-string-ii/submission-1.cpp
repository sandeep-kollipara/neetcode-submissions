class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        int repeats;
        for (auto c: s) {
            if (!stk.empty() and c==stk.top().first) repeats=stk.top().second+1;
            else repeats = 1;
            stk.push({c,repeats});
            if (repeats==k) {
                for (int i=0; i<k; i++) stk.pop();
            }
        }
        string t(stk.size(), ' ');
        int i=t.size()-1;
        while (i>=0) {
            t[i] = stk.top().first;
            stk.pop();
            i--;
        }
        return t;
    }
};