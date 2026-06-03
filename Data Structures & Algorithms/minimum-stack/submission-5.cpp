class MinStack {
    int last=-1, min=INT_MAX;
    vector<int> arr;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (last+1 < arr.size()) arr[last+1] = val;
        else arr.push_back(val);
        last++;
        if (last == 0) min = arr[last];
        if (min > arr[last]) min = arr[last];
    }
    
    void pop() {
        if (last > -1) {
            if (arr[last] == min) {
                min = INT_MAX;
                for (int i=0; i<last; i++) {
                    if (arr[i] < min) min = arr[i];
                }
            }
            last--;
        }
    }
    
    int top() {
        if (last > -1) return arr[last];
        else return 0;
    }
    
    int getMin() {
        return min;
    }
};
