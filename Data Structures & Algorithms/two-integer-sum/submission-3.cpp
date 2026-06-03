class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums_original = nums;
        sort(nums.begin(), nums.end());
        int i=0;
        int j=nums.size()-1;
        while(nums[i] + nums[j] != target){
            if(nums[i] + nums[j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        int low = nums[i];
        int high = nums[j];
        int x=-1, y=-1;
        for (int w=0; w < nums_original.size(); w++){
            if (low != high){
                if(nums_original[w]==low){
                    x = w;
                }
                if(nums_original[w]==high){
                    y = w;
                }
            }
            else{
                if(nums_original[w]==low and x==-1){
                    x = w;
                }
                if(nums_original[w]==high){
                    y = w;
                }
            }
        }
        vector<int> result;
        if (x > y){
            result = {y, x};
        }
        else{
            result = {x, y};
        }
        return result;
    }
};
