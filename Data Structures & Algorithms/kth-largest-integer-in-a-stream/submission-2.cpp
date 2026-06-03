class KthLargest {
public:
    //int kth_largest;
    int k_class;
    priority_queue<int,vector<int>,greater<int>> pq; //min heap

    KthLargest(int k, vector<int>& nums) {
        k_class=k;
        for(int i=0; i<nums.size(); i++) pq.push(nums[i]);
        while (pq.size()>k) pq.pop();
        //kth_largest = pq.top()
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size()>k_class)pq.pop();
        return pq.top();
    }
};
