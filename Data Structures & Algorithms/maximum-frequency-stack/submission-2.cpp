class FreqStack {
    struct trio{
        int* first; // freq is shared
        int second; // time is individual
        int third; // val is individial
    };
    unordered_map<int,int*> hashmap; // map element to freq
    vector<trio> maxheap; // map freq and time to element and order them respectively
    int time;
public:
    FreqStack() {
        time=0;
    }
    
    void push(int val) {
        time++;
        auto cmp=[](const trio a, const trio b) {
            if (*a.first == *b.first) return a.second < b.second;
            return *a.first < *b.first;
        };
        // check hashmap if element exists, if yes then (not increment) insert and heapify
        trio neuva;
        if (hashmap.find(val)!=hashmap.end()) {
            (*hashmap[val])++;
            int* freq = hashmap[val];
            neuva = {freq, time, val};
        } else { // else no then insert to both hashmap and maxheap as new entry
            int* freq = new int(1);
            neuva = {freq, time, val}; // make_pair(freq,val);
            hashmap[val] = freq;
        }
        maxheap.push_back(neuva);
        push_heap(maxheap.begin(), maxheap.end(), cmp);
    }
    
    int pop() {
        auto cmp=[](const trio a, const trio b) {
            if (*a.first == *b.first) return a.second < b.second;
            return *a.first < *b.first;
        };
        // extract from top of heap, insert back with one less frequency (>0)
        // update the hashmap respectively
        if (maxheap.size()) {
            int pop = maxheap[0].third;
            if (*maxheap[0].first>1) {
                pop_heap(maxheap.begin(), maxheap.end(), cmp);
                (*maxheap.back().first)--;
                maxheap.pop_back();
                make_heap(maxheap.begin(), maxheap.end(), cmp);
            } else {
                pop_heap(maxheap.begin(), maxheap.end(), cmp);
                maxheap.pop_back();
                hashmap.erase(pop);
            }
            return pop;
        }
        return -1;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */