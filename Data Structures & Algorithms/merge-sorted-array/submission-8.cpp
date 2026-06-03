class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=0; i<n; i++) {
            nums1[i+m] = nums2[i];
        }
        auto merge_it=[](vector<int> arr1, vector<int> arr2) -> vector<int> {
            int i=0, j=0;
            vector<int> arr(arr1.size()+arr2.size(), 0);
            for (int k=0; k<arr.size(); k++) {
                if (i < arr1.size() && (j >= arr2.size() || arr1[i] <= arr2[j])) {
                    arr[k] = arr1[i];
                    i++;
                } else {
                    arr[k] = arr2[j];
                    j++;
                }
            }
            return arr;
        };
        auto merge_sort=[&](auto&& self, vector<int> arr) -> vector<int> {
            if (arr.size()<=1) return arr;
            int mid = arr.size()/2;
            vector<int> left(arr.begin(), arr.begin()+mid);
            vector<int> right(arr.begin()+mid, arr.end());
            left = self(self, left);
            right = self(self, right);
            return merge_it(left, right);

        };
        nums1 = merge_sort(merge_sort, nums1);
    }
};