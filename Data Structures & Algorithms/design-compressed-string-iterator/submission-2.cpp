class StringIterator {
    int i = 0, j = 1;
    string s;
public:
    StringIterator(string compressedString) {
        s = compressedString;
    }
    
    char next() {
        if (i>=s.length()) return ' ';
        char c = s[i];
        /*if (s[i+1]==(j+48)) {
            i+=2;
            j=1;
        } else {
            j++;
        }*/
        string t;
        int k=i+2;
        while (s[k]>47 and s[k]<58) k++;
        int n = stoi(s.substr(i+1, k-i-1));
        if (n==j) {
            i+=(k-i);
            j=1;
        } else {
            j++;
        }
        //cout << s[i] << ":" << i << endl;
        return c;
    }
    
    bool hasNext() {
        if (i+2>=s.length() and j==s[i+1]) return false;
        return true;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
