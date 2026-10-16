class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0, j=0;
        for (auto c=haystack.begin(); c!=haystack.end(); ++c) {
            if (*c==needle[i]){
                i++;
                if (i==needle.length()) return j-needle.length()+1;
            } else {
                if (i>1) {
                    c-=(i-1);
                    j-=(i-1);
                }
                if (*c==needle[0]) i=1;
                else i=0;
            }
            j++;
        }
        return -1;
    }
};