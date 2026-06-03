class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s[s.length()-1]=='1') return false; // edge case
        unordered_map<int, bool> hash_map;
        function<bool(int)> backtrack=[&](int idx) {
            if (hash_map.find(idx)!=hash_map.end()) return hash_map[idx]; // lookup
            // termination
            if (idx<0) return false;
            else if (idx==0) return true;
            else ;
            // proliferation
            bool res = false;
            for (int i=idx-maxJump; i<=idx-minJump; i++) {
                if (s[i]=='0') res|=backtrack(i);
            }
            hash_map[idx] = res;
            return res;
        };
        return backtrack(s.length()-1);
    }
};