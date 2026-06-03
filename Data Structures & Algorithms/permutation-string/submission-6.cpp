class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        stack<char> s;
        for (char c: s2) s.push(c);
        unordered_map<char, int> hash_map;
        for (char c: s1) hash_map[c]++;
        unordered_map<char, int> hash_copy(hash_map);
        int usage=0;
        while(!s.empty()) {
            char c = s.top();
            s.pop();
            cout << "stack pop: " << c << endl;
            if (hash_copy.find(c)!=hash_copy.end()) {
                hash_copy[c]--;
                usage++;
                if (hash_copy[c]==0) hash_copy.erase(c);
                if (hash_copy.size()==0) return true;
            }
            else {
                cout << "usage: " << usage << endl;
                //cout << s.size() << endl;
                if (usage > 1) {
                    string rewind = s2.substr(s.size(), usage);
                    cout << "rewind: " << rewind << endl;
                    for (char c2: rewind) s.push(c2);
                }
                hash_copy = hash_map;
                usage=0;
            }
        }
        return false;
    }
};
