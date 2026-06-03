class MyQueue {
private:
    stack<int> s1, s2;
public:
    MyQueue() {
    }
    
    void push(int x) {
        if (s1.empty()) s1.push(x);
        else s2.push(x);
    }
    
    int pop() {
        int temp = s1.top();
        s1.pop();
        while (s2.size() > 1) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.swap(s2);
        return temp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */