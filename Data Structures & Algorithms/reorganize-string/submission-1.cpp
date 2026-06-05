class Solution {
public:
    string reorganizeString(string s) {
        auto cmp=[](pair<int,char> a, pair<int,char> b) {
            return a.first < b.first;
        };
        priority_queue<pair<int,char>, vector<pair<int,char>>, decltype(cmp)> pq(cmp);
        unordered_map<char, int> hashmap;
        string t = "";
        for (char c: s) {
            hashmap[c]++;
            t+='#';
        }
        //cout << t << endl;
        for (auto& [c, count]: hashmap) pq.push(make_pair(count, c));
        bool change = true;
        int size=0, count=0;
        char c;
        while (change) {
            size = pq.size();
            c = pq.top().second;
            count = pq.top().first;
            for (int i=0; i<t.length(); i++) { // Safe assignment
                if (count>0 and t[i]=='#' 
                and (i+1==t.length() or t[i+1]=='#') 
                and (i==0 or t[i-1]=='#')) {
                    t[i] = c;
                    count--;
                }
            }
            for (int i=0; i<t.length(); i++) { // Desperate assignment
                if (count>0 and t[i]=='#' 
                and (i+1==t.length() or t[i+1]!=c) 
                and (i==0 or t[i-1]!=c)) {
                    t[i] = c;
                    count--;
                }
            }
            if (count==0) pq.pop();
            if (size==pq.size() or pq.size()==0) change=false;
        }
        cout << t << endl;
        if (pq.empty()) return t;
        else return "";
    }
};