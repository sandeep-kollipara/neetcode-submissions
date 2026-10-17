class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> vec;
        for (int i=0; i<wordsDict.size(); i++) {
            if (wordsDict[i]==word1) vec.push_back(i);
        }
        int minimum=INT_MAX;
        for (int i=0; i<wordsDict.size(); i++) {
            if (wordsDict[i]==word2) {
                for(auto& v: vec){
                    minimum = min(minimum, abs(v-i));
                    //v.push_back(abs(grid[i][0]-i));
                }
            }
        }
        return minimum;
    }
};
