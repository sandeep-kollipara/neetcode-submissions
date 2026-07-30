class Solution {
public:
    int shortestWay(string source, string target) {
        int i=0, ans=0, init;
        while (i<target.size()) {
            init = i;
            for (char d: source) {
                if (i<target.size() and target[i]==d) {
                    i++;
                }
            }
            if (i==init) return -1;
            ans++;
        }
        return ans;
    }
};
