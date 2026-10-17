class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int l=0, r=arr.size()-1, m=l+(r-l)/2, res=INT_MAX;
        while (l<=r) {
            if (arr[m]>m) r=m-1;
            else if (arr[m]<m) l=m+1;
            else {
                res = min(res, m);
                r=m-1;
            }
            m=l+(r-l)/2;
        }
        if (res==INT_MAX) return -1;
        return res;
    }
};
