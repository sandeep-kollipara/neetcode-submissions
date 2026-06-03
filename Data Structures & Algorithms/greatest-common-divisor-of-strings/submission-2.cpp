class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int i=1;
        string gcd = "";
        while(i <= str1.length() and i <= str2.length()) {
            if (str1.length()%i==0 and str2.length()%i==0) {
                bool match1=false, match2=false;
                string div = str1.substr(0,i);
                cout << div << endl;
                int j=0;
                while(!div.compare(str1.substr(j*i,i))) {
                    j++;
                    cout << j << endl;
                    if (j==str1.length()/i) {
                        match1 = true;
                        cout << div << " match1" << endl; 
                        break;
                    }
                }
                j=0;
                while(!div.compare(str2.substr(j*i,i))) {
                    j++;
                    if (j==str2.length()/i) {
                        match2 = true;
                        cout << div << " match2" << endl; 
                        break;
                    }
                }
                if (match1 and match2) gcd = div;
            }
            i++;
        }
        return gcd;
    }
};