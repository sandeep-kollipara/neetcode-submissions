class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            nums[i] = nums[i]%2;
            if (i>0 
            and (nums[i]*nums[i-1]!=0 
            or nums[i] + nums[i-1] == 0)) return false;
        }
        return true;
    }
};