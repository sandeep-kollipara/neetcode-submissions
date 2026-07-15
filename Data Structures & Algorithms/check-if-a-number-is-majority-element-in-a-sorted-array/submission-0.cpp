class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        // binary search for element just less than target
        int l=0, r=nums.size()-1, m=l+(r-l)/2;
        while (l<=r) {
            if (nums[m]<target) l = m+1;
            else r = m-1;
            m=l+(r-l)/2; 
        }
        int less = m;
        cout << "less: " << less << endl;
        // binary search for element just more than target
        l=0; 
        r=nums.size()-1;
        m=l+(r-l)/2;
        while (l<=r) {
            if (nums[m]>target) r = m-1;
            else l = m+1;
            m=l+(r-l)/2; 
        }
        int more = m;
        cout << "more: " << more << endl;
        if (more-less > nums.size()/2) return true;
        return false;
    }
};
