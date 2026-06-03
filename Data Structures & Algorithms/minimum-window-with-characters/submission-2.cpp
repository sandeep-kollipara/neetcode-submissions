class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size()<t.size()) return ""; // edge case
        unordered_map<char, int> hash_map;
        for (char c: t) hash_map[c]++;
        unordered_map<char, int> t_map(hash_map);
        int l=0, r=0, matches=0;
        vector<string> subs;
        while(l!=s.size() and r!=s.size()) {
            r=l; // moved to beginning to avoid inf loop
            while (matches<t.size() and r<s.size()) { // finding matches by moving r
                r++;
                if (t_map.find(s[r-1])!=t_map.end()) {
                    if (t_map[s[r-1]]<=0) t_map[s[r-1]]--; // let it go to negatives
                    else {
                        t_map[s[r-1]]--;
                        cout << "l: " << l << " r: " << r << " ";
                        cout << "match found: " << s[r-1] << endl;
                        matches++;
                    }
                }
                if (r==s.size()) break;
            }
            string substring;
            if (matches==t.size()) substring = s.substr(l,r-l);
            while (matches==t.size() and l<r){ // minimizing substring by moving l
                l++;
                if (t_map.find(s[l-1])!=t_map.end()) {
                    if (t_map[s[l-1]]>=hash_map[s[l-1]]
                    or t_map[s[l-1]]<0) t_map[s[l-1]]++; // do nothing if exceeds original
                    else {
                        t_map[s[l-1]]++;
                        cout << "T-map: " << t_map[s[l-1]] << endl;
                        cout << "Hash-map: " << hash_map[s[l-1]] << endl;
                        cout << "l: " << l << "r: " << r << " ";
                        cout << "reverse match found: " << s[l-1] << endl;
                        matches--;
                    }
                }
                if (matches==t.size()) substring = s.substr(l,r-l);
                if (l==r) break;
            }
            if (substring!="") subs.push_back(substring);
            //r=l;
            cout << "l: " << l << "r: " << r << endl;
            t_map = hash_map;
            matches=0;
            //if (subs.size()==4) break;
        }
        int min = s.size()+1;
        string min_win_sub;
        for (string str: subs) {
            cout << str << endl;
            if (str.size() < min) {
                min = str.size();
                min_win_sub = str;
            }
        }
        return min_win_sub;
    }
};
