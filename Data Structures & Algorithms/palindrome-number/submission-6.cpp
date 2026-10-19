class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int y=x, digits=0;
        while(y) {
            y/=10;
            digits++;
        }
        //cout << digits << endl;
        int i=0;
        while (i<digits/2){
            y=10*y+(x%10);
            x/=10;
            i++;
        }
        if (digits%2) x/=10;
        //cout<< x<< " "<<y;
        return x==y;
    }
};