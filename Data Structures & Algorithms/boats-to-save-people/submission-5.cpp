class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        unordered_map<int,int> hash_map;
        for (int i: people) hash_map[i]++;
        int boats=0, saved=0;
        while (saved < people.size()){
            //cout << boats << endl;
            boats++;
            int capacity = limit, unused=0, slots=0;
            while (capacity>0 and slots<2){
                if (hash_map[capacity]>0) {
                    hash_map[capacity]--;
                    saved++;
                    slots++;
                    capacity = unused;
                    unused = 0;
                } else {
                    unused++;
                    capacity--;
                }
            }
        }
        return boats;
    }
};