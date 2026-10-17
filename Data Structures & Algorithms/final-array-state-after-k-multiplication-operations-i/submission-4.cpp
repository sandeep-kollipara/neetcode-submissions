class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp=[&](int a, int b){
            if (nums[a]==nums[b]) return a > b;
            return nums[a] > nums[b];
        };
        priority_queue<int,vector<int>,decltype(cmp)> minheap(cmp);
        for (int i=0; i<nums.size(); i++) {
            minheap.push(i);
        }
        for (int i=0; i<k; i++) {
            int minimum = minheap.top();
            minheap.pop();
            nums[minimum]*=multiplier;
            minheap.push(minimum);
        }
        return nums;
    }
};