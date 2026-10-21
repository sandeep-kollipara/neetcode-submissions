class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        auto timeline=[&](int time)->pair<int,int>{
            int start=((1+time/nums.size())%2)*(time%nums.size());
            int end=((1+time/nums.size())%2)*nums.size()+((time/nums.size())%2)*(time%nums.size());
            return {start, end};
        };
        vector<int> res;
        for (auto& v: queries) {
            pair<int,int> index = timeline(v[0]);
            //cout << index.first << " " << index.second << endl;
            if (v[1]<index.second-index.first) {
                res.push_back(nums[index.first+v[1]]);
            } else res.push_back(-1);
        }
        return res;
    }
};
