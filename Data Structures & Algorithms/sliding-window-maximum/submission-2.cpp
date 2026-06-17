class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // max heap - push and pop by the sliding window so O(nlogk) worst case
        vector<int> result(nums.size()-k+1, 0);
        int max_ele;
        priority_queue<pair<int,int>> pq;
        for (int i=0; i<nums.size(); i++) {
            pq.push({nums[i], i});
            while (pq.size()>k and pq.top().second <= i - k) pq.pop();
            if (i-k+1>-1) result[i-k+1] = pq.top().first;
        }
        return result;
    }
};
