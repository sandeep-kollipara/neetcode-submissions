class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        function<vector<int>(vector<int>)> merge_sort=[&](vector<int> arr) {
            // halve it and recurse
            if (arr.size()>1) {
                int mid = arr.size()/2, i=0, j=0;
                vector<int> left = merge_sort(vector<int>(arr.begin(), arr.begin()+mid));
                vector<int> right = merge_sort(vector<int>(arr.begin()+mid, arr.end()));
                vector<int> merge;
                while (i<left.size() or j<right.size()) {
                    if (i==left.size()) {
                        merge.push_back(right[j]);
                        j++;
                    } else if (j==right.size()) {
                        merge.push_back(left[i]);
                        i++;
                    } else {
                        if (left[i]<right[j]) {
                            merge.push_back(left[i]);
                            i++;
                        } else {
                            merge.push_back(right[j]);
                            j++;
                        }
                    }
                }
                return merge;
            } else {
                return arr;
            }
        };
        return merge_sort(nums);
    }
};