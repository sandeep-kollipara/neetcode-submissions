class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int temp;
        for (int i=0; i<nums.size(); i++) {
            // 2 possibilities: index match or not
            if (nums[i]==i+1) { // match
                continue;
            } else { //mismatch - swap until equal
                while (nums[nums[i]-1]!=nums[i]) {
                    temp = nums[nums[i]-1];
                    nums[nums[i]-1] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]==i+1) continue;
            else res.push_back(i+1);
        }
        //for (auto i: nums) cout << i << " ";
        return res;
    }
};