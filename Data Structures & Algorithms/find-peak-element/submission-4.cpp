class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int L=0, H=nums.size()-1, M=L+(H-L)/2;
        while (L<=H) {
            // check for peak
            if ((M+1==nums.size() or (M+1<nums.size() and nums[M+1]<nums[M])) 
            and (M==0 or (M-1>=0 and nums[M-1]<nums[M]))) return M;
            // check slope and climb up
            else if (M+1<nums.size() and nums[M+1]>nums[M]) L = M+1;
            else H = M-1;
            M=L+(H-L)/2;
            //cout << L << "," << M << "," << H << endl;
        }
        return M;
    }
};