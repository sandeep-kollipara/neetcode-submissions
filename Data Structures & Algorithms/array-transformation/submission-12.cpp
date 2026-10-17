class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int change=INT_MAX;
        int j=0;
        while (j<100) {
            for (int i=1; i<arr.size()-1; i++) {
                if (arr[i-1]<arr[i] and arr[i]>arr[i+1]) {
                    change = min(min(arr[i]-arr[i-1],arr[i]-arr[i+1]),change);
                } else if (arr[i-1]>arr[i] and arr[i]<arr[i+1]) {
                    change = min(min(arr[i-1]-arr[i],arr[i+1]-arr[i]),change);
                }
            }
            cout << change;
            vector<int> arr2(arr);
            for (int i=1; i<arr.size()-1; i++) {
                if (arr[i-1]<arr[i] and arr[i]>arr[i+1]) arr2[i]-=(change/2+change%2);
                else if (arr[i-1]>arr[i] and arr[i]<arr[i+1]) arr2[i]+=(change/2+change%2);
            }
            arr = arr2;
            j++;
        }
        return arr;
    }
};
