class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        auto cmp=[](pair<int,int> a, pair<int,int> b){
            if (a.first > b.first) return true;
            else if (a.first==b.first) {
                if (a.second > b.second) return true;
                else return false;
            }
            else return false;
        };
        /*struct cmp{
            bool operator()(pair<int,int> a, pair<int,int> b){ // min heap
                if (a.first > b.first) return true;
                else if (a.first==b.first) {
                    if (a.second > b.second) return true;
                    else return false;
                }
                else return false;
            }
        };*/
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq1(cmp); // enqueue time
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq2(cmp); // processing time
        int i=0;
        for (vector<int> task: tasks) {
            pair<int,int> node = {task[0],i};
            pq1.push(node);
            i++;
        }
        vector<int> process;
        int t=0;
        while (!pq1.empty()) {
            if (t==0) {
                pair<int,int> node = pq1.top();
                t = node.first;
                pq1.pop();
                node.first = tasks[node.second][1];
                pq2.push(node);
                while (!pq1.empty() and pq1.top().first <= t) {
                    pair<int,int> node = pq1.top();
                    pq1.pop();
                    node.first = tasks[node.second][1];
                    pq2.push(node);
                }
                node = pq2.top();
                t += node.first;
                pq2.pop();
                process.push_back(node.second);
            } else {
                // process pq1 until completion time of pq2's top process
                while (!pq1.empty() and pq1.top().first <= t) {
                    pair<int,int> node = pq1.top();
                    pq1.pop();
                    node.first = tasks[node.second][1];
                    pq2.push(node);
                }
                // process pq2 by 1 and update t
                if (!pq2.empty()) {
                    pair<int,int> node = pq2.top();
                    pq2.pop();
                    process.push_back(node.second);
                    t += node.first;
                } else t++; //else if (!pq1.empty()) t=pq1.top().first;
            }
        }
        while (!pq2.empty()) {
            pair<int,int> node = pq2.top();
            pq2.pop();
            process.push_back(node.second);
        }
        return process;
    }
};