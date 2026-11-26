class Solution {
public:
    bool nimGame(vector<int>& piles) {
        int i=0;
        for (int j: piles) i^=j;
        return i!=0;
    }
};
