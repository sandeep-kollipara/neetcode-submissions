class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto findMin = [](vector<int> &nums) {
            //if (nums.size() < 2) return 0;
            int mid, low = 0;
            int high = nums.size()-1;
            while(high-low>1){
                mid = ceil((low + high)/2);
                //cout << nums[low] << " " << nums[mid] << " " << nums[high] <<endl;
                if (nums[mid] < nums[high]) high = mid;
                else low = mid;
            }
            if (nums[low]<nums[high]) /*return nums[low];*/ return low;
            else /*return nums[high];*/ return high;
        };
        int start = findMin(nums);
        cout << "Index of the low:" << start << endl;
        vector<int> sorted_nums_1;
        if (nums.size() <2 or start==0){
            sorted_nums_1 = nums;
        }
        else{
            sorted_nums_1 = vector<int>(nums.begin() + start, nums.end());
            vector<int> sorted_nums_2 = vector<int>(nums.begin(), nums.begin() + start);
            sorted_nums_1.insert(sorted_nums_1.end(), sorted_nums_2.begin(), sorted_nums_2.end());
        }
        for (int i: sorted_nums_1) cout << i << " ";
        cout << endl;
        auto binSearch = [](vector<int> &nums, int target) { /* nums is sorted array */
            //if (nums.size() < 2 and nums[0]==target) return 0;
            //else if (nums.size() < 2 and nums[0]!=target) return -1;
            int mid, low = 0;
            int high = nums.size()-1;
            while(high-low>1){
                mid = ceil((low + high)/2);
                cout << nums[low] << " " << nums[mid] << " " << nums[high] <<endl;
                if (nums[mid] < target) low = mid;
                else high = mid;
            }
            if (nums[low] == target) return low;
            if (nums[high] == target) return high;
            else return -1;
        };
        int transformed_idx = binSearch(sorted_nums_1, target);
        cout << "Index of the target pre-transform:" << transformed_idx << endl;
        int idx = -1;
        if (transformed_idx == -1) idx = -1;
        else if (start + transformed_idx < nums.size()) idx = transformed_idx + start;
        else idx = transformed_idx + start - nums.size();
        cout << "Index of the target post-transform:" << idx << endl;
        return idx;
    }
};
