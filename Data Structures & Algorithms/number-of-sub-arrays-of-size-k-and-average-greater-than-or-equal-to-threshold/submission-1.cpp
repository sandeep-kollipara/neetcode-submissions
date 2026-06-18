class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0, j=k-1, out=0;
        float moving_sum=0;
        for (int l=i; l<=j; l++) moving_sum+=arr[l];
        while (j<arr.size()) {
            if (i>0) {
                moving_sum-=arr[i-1];
                moving_sum+=arr[j];
            }
            if (moving_sum >= k*threshold) out++;
            i++;
            j++;
        }
        return out;
    }
};