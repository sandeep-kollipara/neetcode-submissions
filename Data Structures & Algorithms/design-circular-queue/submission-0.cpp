class MyCircularQueue {
private:
    int init, final, size, fill;
    int* arr;
public:
    MyCircularQueue(int k) {
        // init: start of q (0->k), 
        // final: end of q + 1 (0->k), 
        // size: allocated array size
        // fill: array size used
        init=0, final=k-1, size=k, fill=0;
        arr = new int[size];
        for (int i=0; i<size; i++) {
            arr[i] = -1;
        }
    }
    
    bool enQueue(int value) {
        if (fill==size) return false;
        if (final+1==size) final=0;
        else final++;
        arr[final] = value;
        fill++;
        return true;
    }
    
    bool deQueue() {
        if (fill==0) return false;
        arr[init] = -1;
        init++;
        if (init==size) init=0;
        fill--;
        return true;
    }
    
    int Front() {
        if (fill==0) return -1;
        return arr[init];
    }
    
    int Rear() {
        if (fill==0) return -1;
        return arr[final];
    }
    
    bool isEmpty() {
        return fill==0;
    }
    
    bool isFull() {
        return fill==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */