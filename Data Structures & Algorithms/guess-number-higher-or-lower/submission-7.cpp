/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        auto bin_range_search=[](int n){
            int l = 0, h = n, m = l + (h-l)/2;
            while(l <= h) {
                if (guess(m) > 0) l = m+1;
                else if (guess(m) < 0) h = m-1;
                else return m;
                m = l + (h - l)/2;
            }
            return -1;
        };
        return bin_range_search(n);
    }
};