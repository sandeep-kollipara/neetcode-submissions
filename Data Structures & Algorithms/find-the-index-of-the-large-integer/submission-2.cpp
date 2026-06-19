/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        // 2 cases - array length is even or odd
        int l=0, r, x, api_resp, y;
        if (reader.length()%2) y = reader.length()-2;
        else y = reader.length()-1;
        r = (y+l)/2;
        x = (y+l)/2+1;
        while (y-l>1 and r!=x) {
            api_resp = reader.compareSub(l, r, x, y);
            if (api_resp > 0) { // left contains the big element
                l = l;
                y = r;
            } else if (api_resp < 0) { // right contains the big element
                l = x;
                y = y;
            } else { // must be the odd element
                return y+1; //reader.length()-1;
            }
            if ((y-l+1)%2) y--; // adjustment if odd length 
            r = (y+l)/2;
            x = (y+l)/2+1;
        }
        // only 2 will remain
        api_resp = reader.compareSub(l, l, y, y);
        if (api_resp > 0) return l;
        else if (api_resp < 0) return y;
        else return y+1; //reader.length()-1;
        /*if (reader.length()%2==0) { // even case
            int l=0, r, x, y=reader.length()-1, api_resp;
            r = (y+l)/2;
            x = (y+l)/2+1;
            while (y-l>1 and r!=x) {
                api_resp = reader.compareSub(l, r, x, y);
                if (api_resp > 0) { // left contains the big element
                    l = l;
                    y = r;
                } else if (api_resp < 0) { // right contains the big element
                    l = x;
                    y = y;
                } else { // impossible
                    return -1;
                }
                r = (y+l)/2;
                x = (y+l)/2+1;
            }
            // only 2 will remain
            api_resp = reader.compareSub(l, l, y, y);
            if (api_resp > 0) return l;
            else if (api_resp < 0) return y;
            else return -1;
        } else { // odd case
            int l=0, r, x, y=reader.length()-2, api_resp;
            r = (y+l)/2;
            x = (y+l)/2+1;
            while (y-l>1 and r!=x) {
                api_resp = reader.compareSub(l, r, x, y);
                if (api_resp > 0) { // left contains the big element
                    l = l;
                    y = r;
                } else if (api_resp < 0) { // right contains the big element
                    l = x;
                    y = y;
                } else { // must be the odd element
                    return reader.length()-1;
                }
                r = (y+l)/2;
                x = (y+l)/2+1;
            }
            // only 2 will remain
            api_resp = reader.compareSub(l, l, y, y);
            if (api_resp > 0) return l;
            else if (api_resp < 0) return y;
            else return reader.length()-1;
        }*/
    }
};
