class Solution {
public:
    int hammingWeight(uint32_t n) {
        auto kernighan_algo=[](int n){
            int count=0;
            while (n) {
                n&=(n-1);
                count++;
            }
            return count;
        };
        return kernighan_algo(n);
    }
};
