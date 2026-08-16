class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> hashmap;
        for (auto s: arr) hashmap[s]++;
        int n=0;
        for (auto s: arr) {
            if (hashmap[s]==1) n++;
            if (n==k) return s;
        }
        return "";
    }
};