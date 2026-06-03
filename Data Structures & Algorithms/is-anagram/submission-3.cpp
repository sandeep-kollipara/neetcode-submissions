class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashmap_s;
        unordered_map<char, int> hashmap_t;
        for (char c: s){
            if(hashmap_s.find(c) != hashmap_s.end()){
                hashmap_s[c]++;
            }
            else{
                hashmap_s[c]=1;
            }
        }
        for (char c: t){
            if(hashmap_t.find(c) != hashmap_t.end()){
                hashmap_t[c]++;
            }
            else{
                hashmap_t[c]=1;
            }
        }
        if (hashmap_s == hashmap_t){
            return true;
        }
        return false;
    }
};
