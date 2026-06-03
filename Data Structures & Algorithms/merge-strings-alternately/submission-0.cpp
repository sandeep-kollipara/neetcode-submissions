class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merge;
        while(word1.length()!=0 or word2.length()!=0) {
            if (word1.length()!=0) {
                merge+=word1[0];
                word1.erase(0,1);
            }
            if (word2.length()!=0) {
                merge+=word2[0];
                word2.erase(0,1);
            }
        }
        return merge;
    }
};