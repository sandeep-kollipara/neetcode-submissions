class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        return accumulate(target.begin(),target.end(),0)==accumulate(arr.begin(),arr.end(),0);
    }
};
