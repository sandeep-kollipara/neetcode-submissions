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
        int low=1, high=n, mid;
        while (high - low > 1) {
            mid = (high>>1) + (low>>1); //(high+low)/2; Avoids integer 
            if ((low & 1) and (high & 1)) mid++;
            if (guess(mid)==0) return mid;
            else if (guess(mid)>0) low = mid;
            else high = mid;
        }
        if (guess(low)) return high;
        else return low;
    }
};