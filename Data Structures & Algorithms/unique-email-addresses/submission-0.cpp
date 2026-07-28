class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        auto find_local_and_domain=[](string email) {
            int at;
            for (int i=0; i<email.length(); i++) {
                if (email[i]=='@') {
                    at=i;
                    break;
                }
            }
            return make_pair(email.substr(0, at), email.substr(at+1,email.length()-at-1));
        };
        unordered_set<string> hashset;
        for (auto s: emails) {
            pair<string, string> local_domain = find_local_and_domain(s);
            string local;
            for (auto c: local_domain.first){
                if (c!='.') local+=c;
                if (c=='+') break;
            }
            string e = local + '@' + local_domain.second;
            hashset.insert(e);
        }
        return hashset.size();
    }
};