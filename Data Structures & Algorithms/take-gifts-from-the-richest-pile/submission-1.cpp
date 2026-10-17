class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxheap;
        long long sum=0;
        for (int i: gifts) {
            maxheap.push(i);
            sum+=i;
        }
        for (int i=0; i<k; i++) {
            int highest = maxheap.top();
            maxheap.pop();
            maxheap.push(sqrt(highest));
            sum-=(highest-sqrt(highest));
        }
        return sum;
    }
};