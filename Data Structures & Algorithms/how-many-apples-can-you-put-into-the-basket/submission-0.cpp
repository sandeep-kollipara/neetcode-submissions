class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int remaining=5000, count=0;
        for (int i: weight) {
            if (remaining-i<0) break;
            count++;
            remaining-=i; 
        }
        return count;
    }
};
