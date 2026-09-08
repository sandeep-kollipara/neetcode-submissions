class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        auto cmp=[](const pair<int,double>& a, const pair<int,double>& b){
            return a.second < b.second;
        };
        unordered_map<int,unordered_map<int,double>> hashmap;
        for (int i=0; i<edges.size(); i++) {
            hashmap[edges[i][0]][edges[i][1]] = succProb[i];
            hashmap[edges[i][1]][edges[i][0]] = succProb[i];
        }
        unordered_set<int> visited;
        priority_queue<pair<int,double>, vector<pair<int,double>>, decltype(cmp)> processing(cmp);
        processing.push({start_node, 1});
        double max_prob = 0;
        while (processing.size()) {
            pair<int,double> neuva = processing.top();
            int next = neuva.first;
            double prob = neuva.second;
            processing.pop();
            visited.insert(next);
            if (next==end_node) max_prob = max(max_prob, prob);
            for (auto& [neighbour, probability]: hashmap[next]) {
                if (visited.find(neighbour)==visited.end()) {
                    processing.push({neighbour, (double)prob*probability});
                }
            }
        }
        return max_prob;
    }
};