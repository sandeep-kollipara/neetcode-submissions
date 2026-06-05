class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        //priority_queue<int, vector<int>, greater<int>> pq; // min_pq
        make_heap(sticks.begin(), sticks.end(), greater<int>());
        int a, b, cumsum=0;
        while(sticks.size()>1) {
            pop_heap(sticks.begin(), sticks.end(), greater<int>());
            a = sticks.back();
            sticks.pop_back();
            pop_heap(sticks.begin(), sticks.end(), greater<int>());
            b = sticks.back();
            sticks.pop_back();
            cumsum+=(a+b);
            sticks.push_back(a+b);
            push_heap(sticks.begin(), sticks.end(), greater<int>());
            cout << cumsum << endl;
        }
        return cumsum;
    }
};
