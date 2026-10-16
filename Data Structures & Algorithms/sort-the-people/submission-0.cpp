class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> hashmap;
        for (int i=0; i<names.size(); i++) {
            hashmap[heights[i]] = names[i];
        }
        sort(heights.begin(), heights.end(), greater<int>());
        for (int i=0; i<names.size(); i++) names[i] = hashmap[heights[i]];
        return names;
    }
};