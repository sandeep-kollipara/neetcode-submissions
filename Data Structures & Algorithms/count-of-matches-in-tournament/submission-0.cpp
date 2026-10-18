class Solution {
public:
    int numberOfMatches(int n) {
        auto one_round=[](auto&& self, int i){
            if (i<2) return 0;
            return i/2+self(self, i/2+i%2);
        };
        return one_round(one_round, n);
    }
};
