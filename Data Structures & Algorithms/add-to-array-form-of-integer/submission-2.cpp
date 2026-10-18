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
        vector<int> front;
        while (add>0) {
            front.push_back(add%10);
            add/=10;
        }
        reverse(front.begin(),front.end());
        front.insert(front.end(),num.begin(), num.end());
        return front;
    }
};
