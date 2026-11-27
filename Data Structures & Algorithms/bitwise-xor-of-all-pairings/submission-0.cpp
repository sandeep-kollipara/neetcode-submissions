class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x=0;
        if (nums2.size()%2) {
            for (int i: nums1) x^=i;
        }
        if (nums1.size()%2) {
            for (int i: nums2) x^=i;
        }
        return x;
    }
};
