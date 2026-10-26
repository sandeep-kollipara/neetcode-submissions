class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        auto get_diff=[&](int i){
            return abs(s[i]-t[i]);
        };
        int i=0, j=0, cost=0, maximum=0;
        while (j<s.length()) {
            bool loop=false;
            // extend window to reach maxCost
            while (j<s.length() and cost<=maxCost) {
                cost+=get_diff(j);
                j++;
                loop=true;
            }
            if (loop and cost>maxCost) {
                j--;
                cost-=get_diff(j);
            }
            // calc maximum
            maximum = max(maximum, j-i);
            // shrink by one char
            cost-=get_diff(i);
            i++;
        }
        maximum = max(maximum, j-i);
        return maximum;
    }
};
