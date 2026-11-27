class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> result;
        int x=0, w=pow(2,maximumBit)-1;
        for (int i: nums) x^=i;
        while (nums.size()) {
            result.push_back(w^x);
            x^=nums.back();
            nums.pop_back();
        }
        return result;
    }
};
