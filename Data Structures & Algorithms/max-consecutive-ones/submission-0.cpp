class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                curr++;
                if (total < curr) total = curr;
            } else curr = 0;
        }
        return total;
    }
};