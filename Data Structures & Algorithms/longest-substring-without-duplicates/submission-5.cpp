class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()==0) return 0;
        int counter = 0;
        int prev_pos = -1, prev_pos_2 = -1, distance;
        vector<int> non_repeat_substr_len = {};
        unordered_map<char, int> hash_map = {}; // only store latest positions
        for (int i=0; i<s.length(); i++){
            if (hash_map.find(s[i])==hash_map.end()){
                hash_map[s[i]]=i;
                distance= i - prev_pos;
            }
            else {
                prev_pos_2 = hash_map[s[i]];
                if (prev_pos_2 > prev_pos) prev_pos = prev_pos_2; 
                distance = i - prev_pos;
                hash_map[s[i]]=i; // repetition
            }
            cout << distance << " ";
            non_repeat_substr_len.insert(non_repeat_substr_len.end(), distance);
        }
        return *max_element(non_repeat_substr_len.begin(), non_repeat_substr_len.end());
    }
};
