class Solution {
public:
    bool isArmstrong(int n) {
        int l=0, m=n, k=0;
        while (n) {
            n/=10;
            k++;
        }
        n=m;
        while(n) {
            l+=(pow(n%10,k));
            n/=10;
        }
        return m==l;
    }
};
