class Solution {
public:
    vector<vector<string>> partition(string s) {
        function<bool(string)> isPalindrome=[](string str) {
            if (str.length()==1) return true;
            for (int i=0;i<str.length()/2; i++) if (str[i]!=str[str.length()-i-1]) return false;
            return true;
        };
        // define T[i] = set of palindromes consisting of ith element and including i
        vector<unordered_set<string>> T(s.length()+1);
        // base case
        unordered_set<string> hash_set;
        T[0] = hash_set;
        // recurrence relation - T[i] = palindrome(T[j] + s[j..i]) for j: 0->i-1
        if (s.length()>0) for (int i=1; i<s.length()+1; i++) {
            hash_set.clear();
            hash_set.insert(s.substr(i-1,1)); // itself
            for (int j=i-1; j>-1; j--) {
                string sub = s.substr(j,i-j);
                for (string r: T[j]) if (isPalindrome(r+sub)) hash_set.insert(r+sub);
            }
            T[i] = hash_set;
        }
        vector<vector<string>> out;
        function<vector<vector<string>>(vector<string>, int)> recurse_tree=[&](vector<string> node, int length) {
            if (length==s.length()) return vector<vector<string>>({node});
            vector<vector<string>> tot, rec; 
            for (string r: T[s.length()-length]) {
                vector<string> temp = node;
                temp.insert(temp.begin(), r);
                rec = recurse_tree(temp, length+r.length());
                tot.insert(tot.end(), rec.begin(), rec.end());
            }
            return tot;
        };
        //for (string r: hash_set) out.push_back({r});
        return recurse_tree({},0);
    }
};
