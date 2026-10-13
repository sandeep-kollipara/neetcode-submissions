class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for (auto r: strs) {
            s+='#';
            s+=to_string(r.length());
            s+='@';
            s+=r;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        //cout << s << endl;
        bool len=true, str=false;
        string num, dat;
        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            if (len and c=='#') num="";
            else if (len and c=='@') {
                dat="";
                len=false;
                str=true;
            } else if (len and c!='#') num+=c;
            else if (str) {
                int j=i;
                while (i<j+stoi(num)) {
                    if (i<s.length()) dat+=s[i];
                    i++;
                }
                if (i!=j) i--;
                v.push_back(dat);
                str = false;
                len = true;
            } else {
                cout << "Impossible entry" << endl;
            }
        }
        if (str) v.push_back(dat); // edge case
        return v;
    }
};
