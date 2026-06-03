class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low=0, high=arr.size()-1, mid;
        while (high - low > 1) {
            mid = low + (high-low)/2;
            if (arr[mid] < x) low = mid;
            else if (arr[mid] > x) high = mid;
            else break;
        }
        int center;
        if (abs(arr[mid]-x)<=abs(arr[low]-x)) {
            if (abs(arr[high]-x)<abs(arr[mid]-x)) center = high;
            else center = mid;
        } else center = low;
        cout << arr[low] << " " << arr[mid] << " " << arr[high];
        vector<int> k_closest = {arr[center]};
        int i=center-1,j=center+1;
        while (k_closest.size() < k) {
            if (i == -1) {
                k_closest.push_back(arr[j]);
                j++;
            } else if (j == arr.size()) {
                k_closest.insert(k_closest.begin(), arr[i]);
                i--;
            } else if (x-arr[i] <= arr[j]-x) {
                k_closest.insert(k_closest.begin(), arr[i]);
                i--;
            } else {
                k_closest.push_back(arr[j]);
                j++;
            }
        }
        return k_closest;
    }
};