class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int add=k, cur, div, rem;
        for (int i=num.size()-1; i>-1; i--) {
            cur = div = rem = 0;
            cur = num[i];
            div = (cur+add)/10;
            rem = (cur+add)%10;
            num[i] = rem;
            add = div;
        }
        while (add>0) {
            num.insert(num.begin(),add%10);
            add/=10;
        }
        return num;
    }
};
