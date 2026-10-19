class Solution {
public:
    int maxDepth(string s) {
        int level=0, maximum=0;
        for (char c: s) {
            if (c=='(') level++;
            else if (c==')') level--;
            maximum=max(maximum,level);
        }
        return maximum;
    }
};