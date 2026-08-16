class NumArray {
    vector<int> arr;
    vector<int> prefixsum;
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        prefixsum = vector<int>(arr.size(), 0);
        int sum=0;
        for (int i=0; i<arr.size(); i++) {
            sum+=arr[i];
            prefixsum[i] = sum;
        }
    }
    
    int sumRange(int left, int right) {
        int sum_left=0, sum_right=prefixsum[right];
        if (left>0) sum_left = prefixsum[left-1];
        return sum_right - sum_left;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */