class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l=0, r=-1, white_count=0, minimum=INT_MAX;
        // initialize window
        while (r-l<k-1){
            r++;
            if (blocks[r]=='W') white_count++;
        }
        minimum = white_count;
        // slide the window and find the minimum
        while (r<blocks.size()-1) {
            // add the next
            r++;
            if (blocks[r]=='W') white_count++;
            // remove the first
            if (blocks[l]=='W') white_count--;
            l++;
            // check for minimum
            minimum = min(minimum, white_count);
        }
        return minimum;
    }
};