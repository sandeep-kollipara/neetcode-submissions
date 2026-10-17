class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int l=0, r=arr.size()-1;
        while (l<r) {
            int m=l+(r-l)/2;
            if (arr[m]>=m) r=m;
            else l=m+1;
        }
        if (arr[l]==l) return l;
        return -1;
    }
};
