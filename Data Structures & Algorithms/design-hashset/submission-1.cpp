class MyHashSet {
private:
int arr[31251];
public:
    MyHashSet() {
        fill(arr, arr + 31251, 0);
    }
    
    void add(int key) {
        int idx = key/32, rem = key%32;
        arr[idx] |= (1 << rem);
    }
    
    void remove(int key) {
        int idx = key/32, rem = key%32;
        arr[idx] &= ~(1 << rem);
    }
    
    bool contains(int key) {
        int idx = key/32, rem = key%32;
        return (arr[idx] >> rem) & 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */