class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        auto recurse=[&](auto&& self, int n, int e) {
            if (n+e<numExchange) return n;
            return n + self(self, (n+e)/numExchange, (n+e)%numExchange);
        };
        return recurse(recurse, numBottles, 0);
    }
};
