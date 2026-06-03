class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<vector<int>,int> triad;
        auto comparator=[](triad left, triad right) {
            return left.second > right.second; // max heap
        };
        priority_queue<triad, vector<triad>, decltype(comparator)> lambda_priority_queue(comparator);
        int distance;
        for (int i=0; i<points.size(); i++) {
            distance = pow(points[i][0],2) + pow(points[i][1],2);
            lambda_priority_queue.push(triad({points[i],distance}));
        }
        vector<int> point;
        vector<vector<int>> k_closest_points;
        for (int i=0; i<k; i++) {
            point = lambda_priority_queue.top().first;
            lambda_priority_queue.pop();
            k_closest_points.push_back(point);
        }
        return k_closest_points;
    }
};
