class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size()<=1) return nums[0];
        int l=0, r=nums.size()-1, m;
        m = l+(r-l)/2;
        while (l<r) {
            if ((m%2 and nums[m-1]==nums[m])
            or (m%2==0 and nums[m]==nums[m+1])) l=m+1;
            else if ((m%2 and nums[m]==nums[m+1])
            or (m%2==0 and nums[m-1]==nums[m])) r = m-1;
            else return nums[m];
            m = l+(r-l)/2;
        }
        cout << "l=" << l << ",r=" << r << "."<< endl;
        return nums[m];
        if (l>0 and l<nums.size()-1 and nums[l-1]==nums[l]) return nums[l+1];
        else if (l>0 and l<nums.size()-1 and nums[l]==nums[l+1]) return nums[l-1];
        else return nums[l];
    }
};