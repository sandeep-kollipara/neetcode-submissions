class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<float> dist(points.size(), 0);
        for (int i=0; i<dist.size(); i++) {
            dist[i] = pow(pow(points[i][0], 2) + pow(points[i][1], 2), 0.5);
            cout << dist[i] << endl;
        }
        cout << endl;
        random_device rd;
        mt19937 gen(rd());
        //uniform_int_distribution<int> distro(0, points.size()-1);
        //for (int i=0; i<10; i++) cout << distro(gen) << endl;
        
        auto quick_sort=[&](auto&& self, vector<float>& arr, int l, int r) -> void {
            if (r - l < 1) return;
            
            uniform_int_distribution<int> distro(l, r);
            int p = distro(gen);

            vector<float> arr2(arr);
            vector<vector<int>> points2(points);
            int i = l, j = r;
            for (int k=l; k<r+1; k++) {
                if (k==p) continue;
                else if (arr[k] < arr[p]) {
                    arr2[i] = arr[k];
                    points2[i] = points[k];
                    i++;
                } else {
                    arr2[j] = arr[k];
                    points2[j] = points[k];
                    j--;
                }
            }
            arr2[i] = arr[p];
            points2[i] = points[p];
            arr = arr2;
            points = points2;

            self(self, arr, l, i-1);
            self(self, arr, i+1 ,r);
        };



        quick_sort(quick_sort, dist, 0, dist.size()-1);
        for (int i=0; i<dist.size(); i++) cout << dist[i] << endl;
        vector<vector<int>> top_k_points(points.begin(), points.begin()+k);
        //return points;
        return top_k_points;
    }
};
