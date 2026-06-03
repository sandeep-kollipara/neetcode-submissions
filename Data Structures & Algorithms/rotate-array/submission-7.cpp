class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n_size=nums.size(), x=0, y, temp, temp2;
        if (k>=n_size) k = k%n_size;
        if (n_size == 2*k) { // (1x) repeat loop for k initials 
            cout << "Case I";
            for (int j=0; j<k; j++) {
                x = j;
                for (int i=0; i<1; i++) {
                    if (x+k>=n_size) y = (x+k)%n_size;
                    else y = x+k;
                    temp = nums[y];
                    nums[y] = nums[x];
                    nums[x] = temp;
                    x = y;
                }
            }
        }
        else if (n_size%2==0 and k%2==0) { // (n_size/2 x) repeat loop for 2 initials 
            cout << "Case II";
            for (int j=0; j<2; j++) {
                x = j;
                temp = nums[x];
                for (int i=0; i<n_size/2; i++) {
                    if (x+k>=n_size) y = (x+k)%n_size;
                    else y = x+k;
                    temp2 = nums[y];
                    nums[y] = temp;
                    temp = temp2;
                    //temp = nums[y];
                    //nums[y] = nums[x];
                    //nums[x] = temp;
                    x = y;
                }
            }
        }
        else { // (n_size x) repeat loop for 1 initial 
            cout << "Case III";
            temp = nums[x];
            for (int i=0; i<n_size+1; i++) {
                if (x+k>=n_size) y = (x+k)%n_size;
                else y = x+k;
                temp2 = nums[y];
                nums[y] = temp;
                temp = temp2;
                x = y;
            }
        }
    }
};

// n_size is double of k
//
// n_size is even, k is even
//
// one of n_size or k is odd: n_size number of subsequent swap
// n_size = 7, k = 3
// 3 6 9 12 15 18 21
// 3 6 2  5  1  4  7

