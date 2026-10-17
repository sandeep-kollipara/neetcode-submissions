class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp=[](pair<int,int> a, pair<int,int> b){
            if (a.first==b.first) return a.second > b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> minheap(cmp);
        for (int i=0; i<nums.size(); i++) {
            minheap.push({nums[i],i});
        }
        for (int i=0; i<k; i++) {
            pair<int,int> minimum = minheap.top();
            minheap.pop();
            minheap.push({minimum.first*multiplier,minimum.second});
        }
        while (minheap.size()) {
            pair<int,int> element = minheap.top();
            minheap.pop();
            nums[element.second] = element.first;
        }
        return nums;
    }
};