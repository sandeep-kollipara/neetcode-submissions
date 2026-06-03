class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int inf = 1e9;
        // fix an initial element say nums[0]
        int maximum=-inf, j, size=(signed int)nums.size();
        // expand array in one direction and track sum until its full
        // detect final element as nums[j]
        for (int i=0; i<size; i++) {
            if (nums[i] >  maximum) {
                maximum=nums[i];
                j=i;
            }
        }
        cout << j << endl;
        // use final as initial and do a dual expansion until its full again
        // this time the final elements with max sum is the initial/final element nums[u], nums[v]
        int sum = 0;
        int max_sum_1=-inf, u;
        for (signed int i=j; i>-size+j; i--) { // left expansion
            sum+=nums[(i+size)%size];
            if (sum > max_sum_1) { // not including 0s
                max_sum_1 = sum;
                u=i;
            }
        }
        cout << u << endl;
        cout << max_sum_1 << endl;
        sum = 0;
        int max_sum_2=-inf, v;
        for (int i=j; i<size+u; i++) { // right expansion
            sum+=nums[(i+size)%size];
            if (sum > max_sum_2) { // not including 0s
                max_sum_2 = sum;
                v=i;
            }
        }
        cout << v << endl;
        cout << max_sum_2 << endl;
        int result_1 = max_sum_1 + max_sum_2 - nums[j];
        // perform the operations in reverse
        sum = 0, max_sum_2=-inf;
        for (int i=j; i<size+j; i++) { // right expansion (i<size+j)
            sum+=nums[(i+size)%size];
            if (sum > max_sum_2) { // not including 0s
                max_sum_2 = sum;
                v=i;
            }
        }
        cout << v << endl;
        cout << max_sum_2 << endl;
        sum = 0, max_sum_1=-inf;
        for (signed int i=j; i>-size+v; i--) { // left expansion (i>-size+v)
            sum+=nums[(i+size)%size];
            if (sum > max_sum_1) { // not including 0s
                max_sum_1 = sum;
                u=i;
            }
        }
        cout << u << endl;
        cout << max_sum_1 << endl;
        int result_2 = max_sum_1 + max_sum_2 - nums[j];
        return max(result_1, result_2);
    }
};