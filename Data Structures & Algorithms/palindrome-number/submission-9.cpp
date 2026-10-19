class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 or (x!=0 and x%10==0)) return false;
        int y=0, digits=0;
        while (y<x){
            y=10*y+(x%10);
            x/=10;
        }
        cout << x << " " << y;
        return x==y or x==y/10;
    }
};