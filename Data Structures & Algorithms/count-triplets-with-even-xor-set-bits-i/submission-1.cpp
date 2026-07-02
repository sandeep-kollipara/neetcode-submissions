class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        auto kernighan_algo=[](int a){
            int count=0;
            while (a) {
                a&=(a-1);
                count++;
            }
            return count;
        };
        int odd_a=0, even_a=0;
        for (int i: a) {
            if (kernighan_algo(i)%2) odd_a++;
            else even_a++;
        }
        int odd_b=0, even_b=0;
        for (int i: b) {
            if (kernighan_algo(i)%2) odd_b++;
            else even_b++;
        }
        int odd_c=0, even_c=0;
        for (int i: c) {
            if (kernighan_algo(i)%2) odd_c++;
            else even_c++;
        }
        return even_a*even_b*even_c + even_a*odd_b*odd_c + odd_a*even_b*odd_c + odd_a*odd_b*even_c;
    }
};
