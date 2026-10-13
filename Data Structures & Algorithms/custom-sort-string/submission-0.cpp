class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> hashmap;
        unordered_map<int,char> revhashmap;
        for (int i=0; i<order.size(); i++) {
            hashmap[order[i]]=i+1; // 0 is default
            revhashmap[i+1] = order[i];
        }
        vector<int> nums(s.length());
        string r;
        for (int i=0; i<s.length(); i++) {
            nums[i] = hashmap[s[i]];
            if (hashmap[s[i]]==0) r+=s[i];
        }
        //cout << r;
        sort(nums.begin(), nums.end());
        //int j=0;
        for (int i: nums) {
            if (i!=0) r+=revhashmap[i];
            //s[j] = revhashmap[i];
            //j++;
        }
        //return s;
        return r;
    }
};