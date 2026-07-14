class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char,int> hashmap;
        for (int i=0; i<keyboard.size(); i++) hashmap[keyboard[i]]=i;
        int start=0, end, time=0;
        for (char c: word) {
            end = hashmap[c];
            time+=(abs(end - start));
            start = end;
        }
        return time;
    }
};
