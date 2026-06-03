class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int x = 0;
        int y = 0;
        for(x=0; x<nums.size(); x++){
            for (y=x+1; y<nums.size(); y++){
                if (nums[x] == nums[y]){
                        return true;
                    }
            }
        }
        return false;
    }
};