class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        int i=32;
        for (auto r: strs) {
            s+=r;
            s+='@';
            s+=char((unsigned)i);
            s+='#';
            i++;
            if (i==128) i=32;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        cout << s << endl;
        int i=32, j=0, k=0;
        bool first=false, second=false, third=false;
        for (char c: s) {
            // check
            if (not first and not second and not third and c=='@') {
                first = true;
            } else if (first and not second and not third and c==char((unsigned)i)) {
                second = true;
            } else if (first and second and not third and c=='#') {
                third = true;
            } else if (c=='@') {
                second = false;
            } else {
                first = second = false;
            }
            // reset
            if (first and second and third) {
                i++;
                if (i==128) i=32;
                v.push_back(s.substr(j,k-j-2));
                j=k+1;
                first = second = third = false;
            }
            k++;
        }
        //v.pop_back();
        return v;
    }
};
