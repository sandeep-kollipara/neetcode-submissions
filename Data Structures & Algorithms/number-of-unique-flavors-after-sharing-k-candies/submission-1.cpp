class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int,int> hashmap;
        for (int i: candies) hashmap[i]++;
        if (k==0) return hashmap.size();
        int i=0, j=0, maximum=0;
        while (j<candies.size()) {
            // extend the window
            while (j-i<k) {
                hashmap[candies[j]]--;
                if (hashmap[candies[j]]==0) hashmap.erase(candies[j]);
                j++;
            }
            // calc max
            maximum = max(maximum,(int)hashmap.size());
            // shift by one
            hashmap[candies[i]]++;
            i++;
            if (j<candies.size()) {
                hashmap[candies[j]]--;
                if (hashmap[candies[j]]==0) hashmap.erase(candies[j]);
                j++;
            }
        }
        if (k<candies.size()) maximum = max(maximum,(int)hashmap.size());
        return maximum;
    }
};
