class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hash_map;
        
        hash_map['I'] = 1;
        hash_map['V'] = 5;
        hash_map['X'] = 10;
        hash_map['L'] = 50;
        hash_map['C'] = 100;
        hash_map['D'] = 500;
        hash_map['M'] = 1000;
        
        int i=s.length(), prev, curr, sum=0;
        while (i-->0) {
            cout << i << endl;
            if (i==s.length()-1) prev = 0;
            else prev = hash_map[s[i+1]];
            curr = hash_map[s[i]];
            cout << curr << "," << prev << endl;
            if (curr >= prev) sum+=curr;
            else sum-=curr;
            prev = curr;
            cout << sum << endl;
        }
        return sum;
    }
};