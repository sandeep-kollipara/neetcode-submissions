class Solution {
public:
    vector<int> partitionLabels(string s) {
        /*unordered_map<char,int> start_map, end_map;
        for (int i=97; i<123; i++) {
            start_map[(char)i] = -1;
            end_map[(char)i] = -1;
        }
        for (int i=0; i<s.length(); i++) {
            if (start_map[s[i]]==-1) start_map[s[i]]=i;
            end_map[s[i]]=i;
        }
        vector<int> substrings = {s.length()};
        int start, end;
        for (int i=97; i<123; i++) {
            start=0;
            for (int j: substrings) {
                end = start+j;
                if (start_map[(char)i]>start and )
            }
        }*/
        function<int(vector<int>,vector<int>)> dot_product=[](vector<int> left, vector<int> right) {
            if (left.size()!=right.size()) return -1;
            int result=0;
            for (int i=0; i<left.size(); i++) result += (left[i]*right[i]);
            return result;
        };
        vector<int> left_embedding(26, 0);
        vector<int> right_embedding(26, 0);
        for (int i=0; i<s.length(); i++) {
            right_embedding[(int)s[i]-97]++;
        }
        vector<int> substrings = {};
        for (int i=0; i<s.length(); i++) {
            left_embedding[(int)s[i]-97]++;
            right_embedding[(int)s[i]-97]--;
            if (dot_product(left_embedding, right_embedding)==0) substrings.push_back(i+1);
        }
        if (substrings.size()>1) for (int i=substrings.size()-1; i>0; i--) substrings[i]-=substrings[i-1];
        return substrings;
    }
};
