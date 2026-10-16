// int read4(char* buf4) is provided by the judge.
class Solution {
public:
    Solution() {}

    int read(char* buf, int n) {
        char mem[4];
        int reads=0, iter=1;
        while (iter and reads < n) {
            iter=read4(mem);
            for (int i=0; i<min(iter,n-reads); i++) buf[i+reads] = mem[i];
            reads+=min(iter,n-reads);
        }
        return reads;
    }
};
