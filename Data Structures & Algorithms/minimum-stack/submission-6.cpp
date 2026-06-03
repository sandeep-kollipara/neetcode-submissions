class MinStack {
    int last=-1;
    vector<int> arr, arr2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (last+1 < arr.size()) arr[last+1] = val;
        else {
            arr.push_back(val);
            arr2.push_back(-1);
        }
        last++;
        if (last == 0) arr2[last] = arr[last];
        else if (arr2[last-1] > arr[last]) arr2[last] = arr[last];
        else arr2[last] = arr2[last-1];
    }
    
    void pop() {
        if (last > -1) last--;
    }
    
    int top() {
        if (last > -1) return arr[last];
        else return 0;
    }
    
    int getMin() {
        return arr2[last];
    }
};
