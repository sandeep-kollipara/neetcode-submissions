class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        auto count_set_bits=[](int n){
            int count=0;
            while (n){
                n&=(n-1);
                count++;
            }
            return count;
        };
        int count=0;
        for (int i: a) for (int j: b) for (int k: c) if (count_set_bits(i^j^k)%2==0) count++;
        return count;
    }
};
