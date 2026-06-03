class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red_max=-1, blue_min=nums.size(), temp;
        for (int i=0; i<nums.size(); i++) {
            switch (nums[i]){
                case 0:
                    if (i > red_max) {
                        red_max++;
                        temp = nums[i];
                        nums[i] = nums[red_max];
                        nums[red_max] = temp;
                        i--;
                    }
                    break;
                case 1:
                    if (i <= red_max or i >= blue_min) {
                        //This should never execute
                    }
                    break;
                case 2:
                    if (i < blue_min) {
                        blue_min--;
                        temp = nums[i];
                        nums[i] = nums[blue_min];
                        nums[blue_min] = temp;
                        i--;
                    }
                    break;
            }
        }
    }
};