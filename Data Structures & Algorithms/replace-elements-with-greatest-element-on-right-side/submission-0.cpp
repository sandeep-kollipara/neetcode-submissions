class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatest = -1, temp;
        for (int i = arr.size()-1; i >= 0; i--) {
            if (greatest < arr[i]) temp = arr[i];
            arr[i] = greatest;
            greatest = temp;
        }
        return arr;
    }
};