class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z=-1, n=0;
        while (n<nums.size()) {
            if (nums[n]==0 and z==-1) z=n;
            else if (nums[n]==0 and z!=-1) ;
            else if (nums[n]!=0 and z==-1) ;
            else if (nums[n]!=0 and z!=-1) {
                nums[z] = nums[n];
                nums[n] = 0;
                z = -1;
                n = z;
            }
            n++;
        }
    }
};