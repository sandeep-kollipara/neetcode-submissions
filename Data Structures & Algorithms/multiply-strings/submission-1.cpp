class Solution {
public:
    string multiply(string num1, string num2) {
        function<string(string, string)> add=[&](string a, string b) {
            string c;
            int i=0, carry=0;
            while (i<min(a.length(),b.length())) {
                char x = a[a.length()-1-i], y = b[b.length()-1-i];
                int sum = ((int)x-48 + (int)y-48 + carry);
                carry = sum/10;
                c = (char)(48+sum%10) + c;
                i++;
            }
            if (a.length() > b.length()) {
                if (carry) a = add(a.substr(0,a.length()-b.length()),"1");
                else a = a.substr(0,a.length()-b.length());
                c = a + c;
            } else if (a.length() < b.length()) {
                if (carry) b = add(b.substr(0,b.length()-a.length()),"1");
                else b = b.substr(0,b.length()-a.length());
                c = b + c;
            } else {
                if (carry) c = '1' + c;
            }
            return c;
        };
        function<string(string,string)> mul=[&](string a, string b) {
            string d = "0";
            int k=0;
            for (char i: a) {
                int carry=0;
                string c;
                for (int j=b.length()-1; j>-1; j--) {
                    int prod = ((int)i-48)*((int)b[j]-48) + carry;
                    carry = prod/10;
                    c = (char)(48+prod%10) + c;
                }
                if (carry) c = (char)(carry+48) + c;
                for (int j=1; j<a.length()-k; j++) c = c + '0';
                cout << c << endl;
                d = add(c,d);
                k++;
            }
            while(d[0]=='0' and d.length()>1){
                d = d.substr(1,d.length()-1);
            }
            return d;
        };
        return mul(num1, num2);
    }
};
