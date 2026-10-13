class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> hashmap;
        for (auto i: arr1) hashmap[i]++;
        int j=0;
        for (auto i: arr2) {
            while (hashmap[i]){
                arr1[j] = i;
                hashmap[i]--;
                j++;
            }
        }
        int k=j;
        for (auto& [a, b]: hashmap) {
            while (hashmap[a]) {
                arr1[j] = a;
                hashmap[a]--;
                j++;
            }
        }
        sort(arr1.begin()+k, arr1.end());
        return arr1;
    }
};