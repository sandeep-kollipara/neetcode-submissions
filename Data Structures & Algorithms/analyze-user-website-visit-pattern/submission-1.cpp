class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        struct Trio {
            string user;
            int timestamp;
            string website;
            Trio(string a, int b, string c): user(a), timestamp(b), website(c) {}
        };
        auto cmp=[](Trio a, Trio b){
            if (a.user == b.user) {
                return a.timestamp > b.timestamp;
            } else return a.user > b.user;
        };
        priority_queue<Trio, vector<Trio>, decltype(cmp)> minheap(cmp);
        for (int i=0; i<username.size(); i++) {
            Trio neuva = Trio(username[i], timestamp[i], website[i]);
            minheap.push(neuva);
        }
        unordered_map<string,int> hashmap; // contains pattern frequency
        auto find_pattern_frequency=[&](vector<string> websites) {
            //for (auto s: websites) cout << s << " ";
            //cout << endl;
            unordered_set<string> hashset;
            if (websites.size()<3) return ;
            for (int i=0; i<websites.size()-2; i++) {
                for (int j=i+1; j<websites.size()-1; j++) {
                    for (int k=j+1; k<websites.size(); k++){
                        //cout << websites[i]+'_'+websites[j]+'_'+websites[k] << endl;
                        hashset.insert(websites[i]+'_'+websites[j]+'_'+websites[k]);
                    }
                }
            }
            for (auto s: hashset) hashmap[s]++;
        };
        string current_user;
        vector<string> user_history;
        while(minheap.size()) {
            if (current_user!=minheap.top().user) {
                find_pattern_frequency(user_history);
                user_history.clear();
                current_user = minheap.top().user;
            }
            user_history.push_back(minheap.top().website);
            minheap.pop();
        }
        find_pattern_frequency(user_history);
        int max_freq=0;
        string pattern;
        for (auto& [a, b]: hashmap) {
            if (b > max_freq) {
                pattern = a;
                max_freq = b;
            } else if (b == max_freq) {
                pattern = min(pattern, a);
            }
        }
        //cout << max_freq;
        string temp;
        vector<string> result;
        for (char c: pattern) {
            if (c=='_') {
                result.push_back(temp);
                temp="";
            } else temp+=c;
        }
        result.push_back(temp);
        return result;
    }
};