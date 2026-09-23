class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int discrep=0;
        vector<int> original(heights);
        sort(heights.begin(), heights.end());
        for (int i=0; i<heights.size(); i++) {
            if (heights[i]!=original[i]) discrep++;
        }
        return discrep;
    }
};