class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i=0, j=0, k=0;
        vector<int> intersect;
        while (i<arr1.size() and j<arr2.size() and k<arr3.size()) {
            // shift i to the most forward position possible
            while (i<arr1.size()-1 and arr1[i]<max(arr2[j],arr3[k])) i++;
            // move j and k to i or past it
            while (j<arr2.size()-1 and arr2[j]<arr1[i]) j++;
            while (k<arr3.size()-1 and arr3[k]<arr1[i]) k++;
            // compare and move i
            if (arr1[i]==arr2[j] and arr2[j]==arr3[k]) {
                intersect.push_back(arr1[i]);
            }
            i++;
        }
        return intersect;
    }
};
