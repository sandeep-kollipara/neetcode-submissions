class Solution {
public:
    int numberOfDays(int year, int month) {
        unordered_map<int,int> hashmap = {
            {1,31},
            {2,28},
            {3,31},
            {4,30},
            {5,31},
            {6,30},
            {7,31},
            {8,31},
            {9,30},
            {10,31},
            {11,30},
            {12,31}
        };
        if (not (year%400) and month==2) { // multiples of 400
            cout << "1";
            return hashmap[2]+1;
        } else if (not (year%100) and month==2) { // multiples of 100
            cout << "2";
            return hashmap[2];
        } else if (not (year%4) and month==2) { // multiples of 4
            cout << "3";
            return hashmap[2]+1;
        }
        return hashmap[month];
    }
};
