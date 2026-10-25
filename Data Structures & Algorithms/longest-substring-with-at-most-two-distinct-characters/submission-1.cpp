class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i=0, j=-1, maximum=0;
        unordered_map<char,int> hashmap;
        while (j<(int)s.length()) {
            // extend the window until a third distinct is reached
            while (j<(int)s.length() and hashmap.size()<3) {
                j++;
                if (j<(int)s.length()) hashmap[s[j]]++;
            }
            // save the maximum
            //cout << i << "," << j << endl;
            maximum = max(maximum, j-i);
            // shrink the window until the new value is not a duplicate
            while (i<=j and hashmap.size()>2) {
                if (i<=j) {
                    hashmap[s[i]]--;
                    if (hashmap[s[i]]==0) hashmap.erase(s[i]);
                }
                i++;
            }
        }
        return maximum;
    }
};