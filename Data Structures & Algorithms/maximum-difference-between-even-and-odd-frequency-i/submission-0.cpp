class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> hashmap;
        for (auto a: s) {
            hashmap[a]++;
        }
        int max_odd_freq=INT_MIN, /*min_odd_freq=INT_MAX, max_even_freq=INT_MIN,*/ min_even_freq=INT_MAX;
        for (auto [a, b]: hashmap) {
            if (b%2) {
                max_odd_freq = max(b, max_odd_freq);
                //min_odd_freq = min(b, min_odd_freq);
            } else {
                //max_even_freq = max(b, max_even_freq);
                min_even_freq = min(b, min_even_freq);
            }
        }
        return max_odd_freq - min_even_freq;
    }
};