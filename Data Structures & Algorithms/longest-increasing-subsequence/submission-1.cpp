class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // define T[i] = LIS length until the ith element including the ith element
        vector<int> T(nums.size()+1);
        // base case
        T[0] = 0;
        T[1] = 1;
        // recurrence relation
        if (nums.size()>1) for (int i=2; i<nums.size()+1; i++) {
            int j=i;
            T[i]=1;
            while (j-->0) if (nums[j-1]<nums[i-1]) T[i] = max(T[i],T[j]+1);
        }
        for (int i=0; i<T.size(); i++) cout << T[i] << " ";
        return *max_element(T.begin(), T.end());
    }
};
