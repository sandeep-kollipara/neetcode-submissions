class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> hashmap;
        int i=0, j=0;
        while (j<(int)s.length()) {
            bool loop=false;
            // extend the window to the max if hashmap size is <= k
            while (j<(int)s.length() and hashmap.size()<=k) {
                hashmap[s[j]]++;
                j++;
                loop=true;
            }
            if (loop and hashmap.size()>k) {
                j--;
                hashmap[s[j]]--;
                if (hashmap[s[j]]==0) hashmap.erase(s[j]);
            }
            // force slide the window by one
            hashmap[s[j]]++;
            j++;
            hashmap[s[i]]--;
            if (hashmap[s[i]]==0) hashmap.erase(s[i]);
            i++;
        }
        cout << i << "," << j << endl;
        return j-i;
    }
};
