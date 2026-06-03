class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length(), j=b.length();
        string c;
        bool carry=false;
        while (i-->0 or j>0 or carry) {
            j--;
            cout << i << "," << j << endl;
            char x, y, z='0';
            if (i<0) x='0';
            else x=a[i];
            if (j<0) y='0';
            else y=b[j];
            if ((x=='1' and y=='0') or (x=='0' and y=='1')) {
                if (not carry) z='1';
            }
            else if (x=='1' and y=='1') {
                if (carry) z='1';
                carry=true;
            }
            else {
                if (carry) {
                    z='1';
                    carry = false;
                }
            }
            c = z + c;
        }
        return c;
    }
};