class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0; // edge case
        unordered_set<int> hash_set = {};
        for (int i=0; i<nums.size(); i++) hash_set.insert(nums[i]);
        vector<int> dp_array;
        for (int i=0; i<nums.size(); i++){
            // Base case - wrong
            //if (i==0) dp_array.push_back(1);
            // General case
            //else {
                int max_seq=1;
                int j=nums[i];
                while(hash_set.find(j-1)!=hash_set.end()){
                    max_seq++;
                    j--;
                }
                dp_array.push_back(max_seq);
            //}
        }
        for (int i=0; i<dp_array.size(); i++) cout << dp_array[i] << " ";
        cout << endl;
        return *max_element(dp_array.begin(), dp_array.end());
    }
};
