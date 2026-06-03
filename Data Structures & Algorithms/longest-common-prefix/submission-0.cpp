class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int prefix_len=1;
        while(prefix_len<=strs[0].length()) {
            for (string str: strs) {
                string init = strs[0].substr(0,prefix_len);
                if (str.substr(0,prefix_len)==init) continue;
                else return strs[0].substr(0, prefix_len-1);
            }
            prefix_len++;
        }
        return strs[0];
    }
};