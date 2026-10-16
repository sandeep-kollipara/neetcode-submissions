// int read4(char* buf4) is provided by the judge.
class Solution {
public:
    Solution() {}

    int read(char* buf, int n) {
        char mem[4];
        int reads=0, iter=1;
        while (iter and reads < n) {
            iter=read4(mem);
            int count = min(iter, n - reads);
            for (int i=0; i<count; i++) buf[i+reads] = mem[i];
            reads+=count;
        }
        return reads;
    }
};
