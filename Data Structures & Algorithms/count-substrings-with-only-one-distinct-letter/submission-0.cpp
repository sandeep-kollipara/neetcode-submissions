class Solution {
public:
    int countLetters(string s) {
        int len=0, subs=0;
        char prev='\0';
        for (char c: s) {
            if (prev!=c) {
                subs+=(len*(len+1)/2);
                len=0;
                prev=c;
            }
            len++;
        }
        subs+=(len*(len+1)/2);
        return subs;
    }
};
