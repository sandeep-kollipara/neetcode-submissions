class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,priority_queue<int, vector<int>, greater<int>>> hashmapofmaxheap;
        for (auto& v: items) { // O(n) insert since heap take O(log5) time
            hashmapofmaxheap[v[0]].push(v[1]);
            if (hashmapofmaxheap[v[0]].size()>5) hashmapofmaxheap[v[0]].pop();
        }
        vector<vector<int>> res;
        for (auto& [a,b]: hashmapofmaxheap) { // O(n) extract total
            int avg=0;
            while (b.size()) { // O(log5) extract
                //cout << b.size() << " ";
                avg+=b.top();
                b.pop();
            }
            //cout << endl;
            avg/=5;
            res.push_back({a,avg});
        }
        //sort(res.begin(),res.end()); // needed only if hashmap is used instead of treemap
        return res;
    }
};
