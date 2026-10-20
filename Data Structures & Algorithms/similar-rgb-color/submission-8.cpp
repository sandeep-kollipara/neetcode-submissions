class Solution {
public:
    string similarRGB(string color) {
        string first=color.substr(1,2), second=color.substr(3,2), third=color.substr(5,2);
        /*auto hextodec=[](string h) {
            int n=0, i=0;
            while (h!=""){
                int m=0;
                char c = h.back();
                h.pop_back();
                if (c>='0' and c<='9') m+=(c-'0');
                else if (c>='a' and c<='f') m+=(c-'a'+10);
                n+=(pow(16,i)*m);
                i++;
            }
            return n;
        };*/
        auto hextodec=[](char h) {
            int m=0;
            if (h>='0' and h<='9') m+=(h-'0');
            else if (h>='a' and h<='f') m+=(h-'a'+10);
            return m;
        };
        //cout << hextodec(first) << " " << hextodec(second) << " " << hextodec(third);
        //cout << hextodec("11") << " " << hextodec("22") << " " << hextodec("33");
        auto solve_problem=[&](string test) ->string {
            string res;
            if (test[0]==test[1]) return test;
            else if (test[0]<test[1] and hextodec(test[1])-hextodec(test[0])>8) return res+(++test[0])+(test[0]);
            else if (test[0]<test[1] and hextodec(test[1])-hextodec(test[0])<=8) return res+test[0]+test[0];
            else if (test[0]>test[1] and hextodec(test[0])-hextodec(test[1])>8) return res+(--test[0])+(test[0]);
            else if (test[0]>test[1] and hextodec(test[0])-hextodec(test[1])<=8) return res+test[0]+test[0];
            return "";
        };
        string s="#";
        s+=(solve_problem(first)+solve_problem(second)+solve_problem(third));
        replace(s.begin(), s.end(), '`','9');
        replace(s.begin(), s.end(), ';','a');
        return s;
    }
};
