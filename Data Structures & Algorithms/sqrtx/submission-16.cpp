class Solution {
public:
    int mySqrt(int x) {
        int low=0, high=1, mid=x, bits=0;
        while (mid!=0) {
            mid = mid >> 1;
            bits++;
        }
        for (int i=0; i<bits/2+1; i++) high = high << 1;
        if (high > 46340) high = 46340; // edge case
        cout << low << "," << high << endl;
        while (high-low > 1) {
            mid = low + (high-low)/2;
            if (mid*mid==x) return mid;
            else if (mid*mid<x) low = mid;
            else high = mid;
        }
        cout << low << "," << mid << "," << high;
        if (high*high<=x) return high;
        return low;
    }
};