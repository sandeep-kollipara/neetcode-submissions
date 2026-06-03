class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // max heap
        int largest, penultimate;
        for (int i=0; i<stones.size(); i++) pq.push(stones[i]);
        while(pq.size()>1){
            largest=pq.top();
            pq.pop();
            penultimate=pq.top();
            pq.pop();
            if (largest!=penultimate) pq.push(largest-penultimate);
            if (pq.size()==0) return 0;
        }
        return pq.top();
    }
};
