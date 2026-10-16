class TwoSum {
    list<int> linkedlist;
public:
    TwoSum() {
    }
    void add(int number) {
        auto it=linkedlist.begin();
        while(it!=linkedlist.end()){
            if (*it > number) break;
            it=next(it,1);
        }
        linkedlist.insert(it,number);
    }
    bool find(int value) {
        auto start=linkedlist.begin(), end=--linkedlist.end();
        while(start!=end){
            if (value > *start + *end) {
                start++;
            } else if (value < *start + *end) {
                end--;
            } else {
                return true;
            }
        }
        return false;
    }
};
