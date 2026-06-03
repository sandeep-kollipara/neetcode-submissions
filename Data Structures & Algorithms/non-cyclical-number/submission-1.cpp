class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash_set;
        int cal=n, digit;
        while (true) {
            int rem = cal, total = 0;
            for (int i=int(log10(cal)); i>-1; i--) {
                digit = rem / pow(10,i);
                rem = rem % (int)pow(10,i);
                total+=pow(digit, 2);
            }
            cout << total << endl;
            if (total == 1) return true;
            else if (hash_set.find(total)!=hash_set.end()) return false;
            else {
                cal = total;
                hash_set.insert(total);
            }
        }
    }
};
