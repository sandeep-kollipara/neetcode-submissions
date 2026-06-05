class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        typedef struct {
            int first;
            int second;
            int third;
        }trio;
        auto comp=[](trio a, trio b) {
            if (a.first==b.first and a.second==b.second) return a.third > b.third;
            else if (a.first == b.first) return a.second > b.second;
            //if (a.first == b.first) return a.second > b.second;
            else return a.first > b.first;
        };
        priority_queue<trio, vector<trio>, decltype(comp)> pq(comp);
        int dist, idx=0, idx2;
        //vector<int> result(workers.size(), 0);
        vector<bool> bikes_bool(bikes.size(), false);
        for (auto worker: workers) {
            idx2 = 0;
            for (auto bike: bikes) {
                dist = abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
                trio x = {dist, idx, idx2};
                if (!bikes_bool[idx2]) pq.push(x);
                idx2++;
            }
            /*cout << pq.size() << endl;
            result[idx] = pq.top().third;
            bikes_bool[pq.top().third] = true;
            //bikes.erase(bikes.begin()+pq.top().third);
            priority_queue<trio, vector<trio>, decltype(comp)>(comp).swap(pq);
            cout << pq.size() << endl;*/
            idx++;
        }
        vector<int> result(workers.size(), -1);
        for (int i=0; i<workers.size(); i++) {
            while (result[pq.top().second]!=-1 
            or bikes_bool[pq.top().third]) pq.pop();
            result[pq.top().second] = pq.top().third;
            bikes_bool[pq.top().third] = true;
            pq.pop();
        }
        return result;
    }
};
