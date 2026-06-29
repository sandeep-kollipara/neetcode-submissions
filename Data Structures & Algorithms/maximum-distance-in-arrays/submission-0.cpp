class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int first, last;
        auto cmp=[](const pair<int,int> a, const pair<int,int> b){
            return a.first < b.first;
        };
        auto cmp2=[](const pair<int,int> a, const pair<int,int> b){
            return a.first > b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> maxheap(cmp);
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp2)> minheap(cmp2); 
        for (int i=0; i<arrays.size(); i++) { // O(m)
            first = arrays[i][0];
            last = arrays[i][arrays[i].size()-1];
            minheap.push({first, i});
            maxheap.push({last, i});
        }
        if (maxheap.top().second!=minheap.top().second) {
            return maxheap.top().first - minheap.top().first;
        }
        int one, other = -minheap.top().first;
        minheap.pop();
        one = maxheap.top().first - minheap.top().first;
        maxheap.pop();
        other += maxheap.top().first;
        return max(one, other);
    }
};
