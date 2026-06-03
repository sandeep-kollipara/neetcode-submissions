class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<float> dist(points.size(), 0);
        for (int i=0; i<dist.size(); i++) {
            dist[i] = pow(pow(points[i][0], 2) + pow(points[i][1], 2), 0.5);
            cout << dist[i] << endl;
        }
        int m;
        float temp;
        vector<int> v;
        for (int k=1; k<dist.size(); k++) {
            m = k;
            for (int l=k-1; l>=0; l--) {
                if (dist[l] > dist[m]) { // swap the elements
                    temp = dist[l];
                    dist[l] = dist[m];
                    dist[m] = temp;
                    v = points[l];
                    points[l] = points[m];
                    points[m] = v;
                    m = l;
                }
            }
        }
        vector<vector<int>> top_k_points(points.begin(), points.begin()+k);//points.end());
        return top_k_points;
        /*cout << endl;
        for (int i=0; i<dist.size(); i++) {
            cout << dist[i] << endl;
        }*/
        //return points;
    }
};
