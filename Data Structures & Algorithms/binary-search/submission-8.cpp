class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1, m=l+(h-l)/2;
        while (l<=h){
            if (nums[m] < target) l = m+1;
            else if (nums[m] > target) h = m-1;
            else return m;
            m = l+(h-l)/2;
        }
        return -1;
    }
};
