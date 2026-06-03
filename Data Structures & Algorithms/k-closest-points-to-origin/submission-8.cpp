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

            float temp;
            vector<int> v;
            int left = l;
            for (int k=l; k<r+1; k++) {
                if (k==p) continue;
                else if (arr[k] < arr[p]) {
                    temp = arr[k];
                    arr[k] = arr[left];
                    arr[left] = temp;
                    v = points[k];
                    points[k] = points[left];
                    points[left] = v;
                    left++;
                    if (left==p) left++;
                }
            }
            if (left < p) {
                temp = arr[left];
                arr[left] = arr[p];
                arr[p] = temp;
                v = points[left];
                points[left] = points[p];
                points[p] = v;
                p = left;
            } else if (left > p) {
                temp = arr[left-1];
                arr[left-1] = arr[p];
                arr[p] = temp;
                v = points[left-1];
                points[left-1] = points[p];
                points[p] = v;
                p = left - 1;
            } else ;

            self(self, arr, l, p-1);
            self(self, arr, p+1 ,r);
        };


        quick_sort(quick_sort, dist, 0, dist.size()-1);
        for (int i=0; i<dist.size(); i++) cout << dist[i] << endl;
        vector<vector<int>> top_k_points(points.begin(), points.begin()+k);

        return top_k_points;
    }
};
