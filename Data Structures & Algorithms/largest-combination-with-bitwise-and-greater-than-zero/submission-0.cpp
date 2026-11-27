class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> counter(32, 0); // 32 bits
        for (int num: candidates) {
            int i=0;
            while (num) {
                if (num&1) counter[i]++;
                num>>=1;
                i++;
            }
        }
        return *max_element(counter.begin(), counter.end());
    }
};
