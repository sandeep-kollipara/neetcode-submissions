class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int,vector<int>,greater<int>> cookies; // minheap
        priority_queue<int,vector<int>,greater<int>> greed; // minheap
        for (auto a: s) cookies.push(a);
        for (auto b: g) greed.push(b);
        while (!greed.empty() and !cookies.empty()){
            if (cookies.top() >= greed.top()) {
                greed.pop();
                cookies.pop();
            } else cookies.pop();
        }
        return g.size() - greed.size();
    }
};