/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // find the peak and if target > peak return -1
        int len=mountainArr.length(), l=0, r=len-1, m = l+(r-l)/2, curr, left, right, peak;
        while (l<=r) {
            curr = mountainArr.get(m);
            left = mountainArr.get(m-1);
            right = mountainArr.get(m+1);
            if (left<curr and curr<right) l=m+1;
            else if (left>curr and curr>right) r=m-1;
            else {
                peak=m;
                break;
            }
            m = l+(r-l)/2;
        }
        cout << peak << endl;
        int highest = mountainArr.get(peak);
        if (target > highest) return -1; 
        else if (target == highest) return peak;
        // else binary search on the left side first, then right side, else -1
        l=0;
        r=peak-1;
        m = l+(r-l)/2;
        while (l<=r) {
            curr = mountainArr.get(m);
            if (curr<target) l=m+1;
            else if (curr>target) r=m-1;
            else return m;
            m = l+(r-l)/2;
        }
        l=peak+1;
        r=len-1;
        m = l+(r-l)/2;
        while (l<=r) {
            curr = mountainArr.get(m);
            if (curr>target) l=m+1;
            else if (curr<target) r=m-1;
            else return m;
            m = l+(r-l)/2;
        }
        return -1;
    }
};