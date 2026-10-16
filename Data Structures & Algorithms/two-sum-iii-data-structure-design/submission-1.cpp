class TwoSum {
    unordered_map<int,int> hashmap;
public:
    TwoSum() {
    }
    void add(int number) {
        hashmap[number]++;
    }
    bool find(int value) {
        for (auto& [a,b]: hashmap) {
            if (hashmap.find(value-a)!=hashmap.end()) {
                if (value!=2*a) return true;
                else if (value==2*a and b>1) return true;
            }
        }
        return false;
    }
};
