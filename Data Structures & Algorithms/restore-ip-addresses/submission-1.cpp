class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // break the string into permutations(?) of 4 different substrings
        // out of n-1 positions within n length string, find all 4-combinations and then validate them
        auto validate_ip=[](string s){
            vector<string> vec;
            string t;
            int dots=0;
            for (char c: s) {
                if (c!='.') t+=c;
                else {
                    dots++;
                    int a;
                    try {
                        a = stoi(t);
                    } catch (const out_of_range& e) {
                        return false;
                    }
                    if (a>255 or a<0) return false;
                    if (t[0]=='0' and t.size()>1) return false;
                    t="";
                }
            }
            int a;
            try {
                a = stoi(t);
            } catch (const out_of_range& e) {
                return false;
            }
            if (a>255 or a<0) return false;
            if (t[0]=='0' and t.size()>1) return false;
            if (dots!=3) return false;
            return true;
        };
        vector<int> positions(s.length()-1, 0), nullset;
        for (int i=1; i<s.length(); i++) positions[i-1]=i;
        auto backtrack=[](auto&& self, int i, vector<int>& temp, vector<int>& arr, vector<vector<int>>& combs){
            // base case or termination or leaf work
            if (temp.size()==3) {
                combs.push_back(temp);
                return ;
            }
            if (i==arr.size()) return;
            // traversal
            temp.push_back(arr[i]);
            self(self, i+1, temp, arr, combs);
            //while (i+1<arr.size() and arr[i+1]==arr[i]) i++;
            temp.pop_back();
            self(self, i+1, temp, arr, combs);
        };
        vector<vector<int>> combine;
        backtrack(backtrack, 0, nullset, positions, combine);
        vector<string> ips;
        for (auto v: combine) {
            string t(s);
            for (int i=v.size()-1; i>-1; i--) t.insert(v[i],".");
            if (validate_ip(t)) ips.push_back(t);
        }
        return ips;
    }
};