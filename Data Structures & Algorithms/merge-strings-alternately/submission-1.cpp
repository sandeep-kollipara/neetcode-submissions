class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merge = word1;
        int i=0, j=0;
        merge.append(word2);
        while(j<word1.length() or j<word2.length()) {
            if (j<word1.length()) {
                merge[i++]=word1[j];
            }
            if (j<word2.length()) {
                merge[i++]=word2[j];
            }
            j++;
        }
        return merge;
    }
};