class LFUCache {
    struct trio {
        int frequency;
        int timer;
        int key;
    };
    vector<trio> minheap; // frequency timer key
    unordered_map<int,int> hashmap; // key value
    int size, timer, max_capacity;
    // comparator
    /*bool cmp=[](const trio a, const trio b) {
        if (a.frequency == b.frequency) return a.timer > b.timer;
        return a.frequency > b.frequency;
    };*/
    struct cmp{
        bool operator()(const trio& a, const trio& b){
            if (a.frequency == b.frequency) return a.timer > b.timer;
            return a.frequency > b.frequency;
        }
    };
public:
    LFUCache(int capacity) {
        max_capacity = capacity;
        size = 0;
        timer = 0;
    }
    
    int get(int key) {
        // if key not found
        if (hashmap.find(key)==hashmap.end()) return -1;
        // else key found
        timer++;
        // update the existing node in pq and make heap - O(n)
        for (int i=0; i<minheap.size(); i++) if (minheap[i].key==key) {
            minheap[i].frequency++;
            minheap[i].timer = timer;
        }
        make_heap(minheap.begin(), minheap.end(), cmp());
        return hashmap[key];
    }
    
    void put(int key, int value) {
        // process
        timer++;
        if (hashmap.find(key)==hashmap.end()) { // new key
            size++;
            // if max capacity, lose the least frequent and least recent KV pair (remove before adding)
            if (size > max_capacity) {
                pop_heap(minheap.begin(), minheap.end(), cmp());
                int delkey = minheap.back().key;
                hashmap.erase(delkey);
                minheap.pop_back();
                size--;
            }
            // add new node in pq - O(1)
            trio neuva = {1, timer, key};
            minheap.push_back(neuva);
            push_heap(minheap.begin(), minheap.end(), cmp());
        } else { // old key
            // update the existing node in pq and make heap - O(n)
            for (int i=0; i<minheap.size(); i++) if (minheap[i].key==key) {
                minheap[i].frequency = 1;
                minheap[i].timer = timer;
            }
            make_heap(minheap.begin(), minheap.end(), cmp());
        }
        hashmap[key] = value;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */