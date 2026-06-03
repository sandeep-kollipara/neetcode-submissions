class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // define T[i] = number of valid parentheses for i pairs
        vector<unordered_set<string>> T(n+1);
        // base cases
        unordered_set<string> base = {};
        vector<vector<string>> center = {};
        center.push_back({});
        T[0] = base;
        base.insert("()");
        center.push_back({"()"});
        T[1] = base;
        // recurrence relation T[i] = {T[1]T[i-1]+T[2]T[i-2]+...+T[i-1]T[i]+nested}
        unordered_set<string> hash_set;
        if (n > 1) for (int i=2; i<n+1; i++) {
            // combinations
            for (int j=1; j<i; j++) {
                for (string s1: T[j]) {
                    for (string s2: T[i-j]) {
                        hash_set.insert(s1+s2);
                    }
                }
            }
            // nested
            center.push_back({});
            for (string c: T[i-1]){
                center[i].push_back("("+c+")");
                hash_set.insert("("+c+")");
            }
            T[i] = hash_set;
            hash_set.clear();
        }
        vector<string> out;
        for (string s: T[n]) out.push_back(s);
        return out;
    }
};
