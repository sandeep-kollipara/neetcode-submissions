class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> hashset;
        for (char c: s) {
            if (hashset.find(c)==hashset.end()) hashset.insert(c);
            else hashset.erase(c);
        }
        if ((s.length()%2 and hashset.size()==1)
        or (s.length()%2==0 and hashset.size()==0)) return true;
        else return false;
    }
};
