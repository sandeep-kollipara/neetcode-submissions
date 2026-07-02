class Solution {
public:
    vector<int> countBits(int n) {
        auto kernighan_algo=[](int a){
            int count=0;
            while (a) {
                a&=(a-1);
                count++;
            }
            return count;
        };
        vector<int> out;
        for (int i=0; i<=n; i++) out.push_back(kernighan_algo(i));
        return out;
    }
};
