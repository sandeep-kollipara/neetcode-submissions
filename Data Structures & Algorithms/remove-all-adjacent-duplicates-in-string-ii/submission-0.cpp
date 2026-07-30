class Solution {
public:
    string removeDuplicates(string s, int k) {
        auto iter_del_duplicates=[](string s, int k) {
            vector<int> delete_list;
            // initialize the window
            unordered_map<char,int> hashmap;
            int l=0, r=-1;
            while (r<k-1){
                r++;
                hashmap[s[r]]++;
            }
            // slide the window
            while (r<s.length()) {
                if (hashmap.size()==1 and 
                (!delete_list.size() or l>=delete_list.back()+k)) delete_list.push_back(l);
                hashmap[s[l]]--;
                if (hashmap[s[l]]==0) hashmap.erase(s[l]);
                l++;
                r++;
                hashmap[s[r]]++;
            }
            //for (auto a: delete_list) cout << a << " ";
            //cout << endl;
            string t;
            int j=0;
            for (int i=0; i<s.length(); i++) {
                if (j+1<delete_list.size() and i>=delete_list[j+1]) j++;
                if (j<delete_list.size() 
                and i>=delete_list[j] 
                and i<delete_list[j]+k) continue;
                t+=s[i];
            }
            return t;
        };
        string t;
        bool changed=true;
        while (changed) {
            t = iter_del_duplicates(s, k);
            if (s==t) changed=false;
            s=t;
            t="";
        }
        return s;
    }
};