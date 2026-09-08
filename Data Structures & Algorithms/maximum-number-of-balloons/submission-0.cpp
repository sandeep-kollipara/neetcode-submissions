class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> hashmap;
        for (auto a: text) hashmap[a]++;
        int inst=0;
        auto update_hmap=[&](char c){
            if (hashmap.find(c)!=hashmap.end() and hashmap[c]>0) {
                hashmap[c]--;
                return true;
            } else return false;
        };
        while (true) {
            if (!update_hmap('b')
            or !update_hmap('a')
            or !update_hmap('l')
            or !update_hmap('l')
            or !update_hmap('o')
            or !update_hmap('o')
            or !update_hmap('n')) {
                break;
            }
            inst++;
        }
        return inst;
    }
};