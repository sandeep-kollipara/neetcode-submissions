class LRUCache {
private:
    // Linked list definition
    struct ListNode{
        int key;
        int value;
        ListNode* next;
        ListNode* prev;
        ListNode(int key, int value): key(key), value(value), next(nullptr), prev(nullptr) {}
    };
    // key-address store
    unordered_map<int, ListNode*> hash_map; // limit to capacity
    // capacity
    int max_size;
    // lru linked-list
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

public:
    LRUCache(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) {
        cout << "key: " << key << endl;
        cout << "size: " << hash_map.size() << endl;
        if (hash_map.find(key)!=hash_map.end()) {
            // move the node to the end as it is recently used
            ListNode* old = hash_map[key];
            if (head==old and head!=tail) head = head->next;
            if (old!=tail) { // not edge case
                if (old->prev!=nullptr) old->prev->next = old->next;
                if (old->next!=nullptr) old->next->prev = old->prev;
                old->next = nullptr; // since it must be at the end
                old->prev = tail;
                tail->next = old;
                tail = old;
            }
            return hash_map[key]->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        // if limit exceeded and key is new, delete the head of LL and move to next and delete the same in hashmap 
        if (hash_map.size() == max_size and hash_map.find(key)==hash_map.end()) {
            int lru_key = head->key;
            ListNode* temp = head;
            head = head->next;
            if (head!=nullptr) head->prev = nullptr;
            delete temp;
            hash_map.erase(lru_key);
            cout << lru_key << endl;
        }
        // if new key then create new LL node with value at end and map it in hashmap
        if (hash_map.find(key)==hash_map.end()) {
            ListNode* neuva = new ListNode(key, value);
            neuva->prev = tail;
            if (head==nullptr) head = neuva;
            if (tail!=nullptr) tail->next = neuva;
            tail = neuva;
            hash_map[key] = neuva;
        }
        // if old key then lookup LL node in hashmap and update value, also move it to the end
        else {
            ListNode* old = hash_map[key];
            if (head==old and head!=tail) head = head->next;
            old->value = value;
            if (old!=tail) { // not edge case
                if (old->prev!=nullptr) old->prev->next = old->next;
                if (old->next!=nullptr) old->next->prev = old->prev;
                old->next = nullptr; // since it must be at the end
                old->prev = tail;
                tail->next = old;
                tail = old;
            }
        }
    }
};
