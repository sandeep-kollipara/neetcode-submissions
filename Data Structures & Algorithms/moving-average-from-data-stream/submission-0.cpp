class MovingAverage {
    double mov_avg = 0;
    int capacity = 1;
    deque<int> dq;
public:
    MovingAverage(int size) {
        capacity = size;
    }
    
    double next(int val) {
        int curr_size, prev_size=dq.size();
        double front=0;
        dq.push_back(val);
        if (dq.size() > capacity){
            front = dq.front();
            dq.pop_front();
        }
        curr_size = dq.size();
        mov_avg = ((double)mov_avg*(prev_size) + val - front)/curr_size;
        return mov_avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
