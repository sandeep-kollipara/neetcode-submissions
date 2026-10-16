class Solution {
public:
    bool isDecomposable(string s) {
        char prev='\0';
        int len=0;
        bool first=false, valid=true, init=true;
        for (char c: s) {
            if (c==prev) {
                len++;
                if (len>3) len%=3;
            } else {
                if (init) init=false;
                else if (len==3) ;
                else if (len==2 and not first) first=true;
                else {
                    valid=false;
                    break;
                }
                len=1;
                prev=c;
            }
        }
        if (len==3) ;
        else if (len==2 and not first) first=true;
        else valid=false;
        return valid and first;
    }
};
