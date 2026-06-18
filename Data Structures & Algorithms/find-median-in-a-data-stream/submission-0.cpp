class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // inserting
        maxHeap.push(num);
        // balancing
        /*if (minHeap.size() > maxHeap.size()+1) {
            int transfer = minHeap.top();
            minHeap.pop();
            maxHeap.push(transfer);
        }*/
        if (minHeap.size() < maxHeap.size()) {
            int transfer = maxHeap.top();
            maxHeap.pop();
            minHeap.push(transfer);
        }
        while(minHeap.size()>0 and maxHeap.size()>0 and minHeap.top()<maxHeap.top()){
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
            temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
    }
    
    double findMedian() {
        cout << "maxHeap size is " << maxHeap.size() << endl;
        cout << "minHeap size is " << minHeap.size() << endl;
        cout << "maxHeap top is " << maxHeap.top() << endl;
        cout << "minHeap top is " << minHeap.top() << endl;
        if (minHeap.size()==maxHeap.size()) return (double)(minHeap.top()+maxHeap.top())/2;
        else if (minHeap.size() > maxHeap.size()) return minHeap.top();
        else return maxHeap.top();
    }
};
