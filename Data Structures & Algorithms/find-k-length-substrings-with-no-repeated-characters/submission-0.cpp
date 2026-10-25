class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int i=0, j=0, result=0;
        unordered_map<char,int> hashmap;
        while (j<s.length()) {
            // extend to size k if not already done
            while (j-i<k and j<s.length()) {
                hashmap[s[j]]++;
                j++;
            }
            // check hashmap size and k
            //cout << hashmap.size() << endl;
            if (hashmap.size()==k and j-i==k) result++;
            hashmap[s[i]]--;
            if (hashmap[s[i]]==0) hashmap.erase(s[i]);
            i++;
            hashmap[s[j]]++;
            j++;
        }
        if (hashmap.size()==k and j-i==k) result++;
        return result;
    }
};
