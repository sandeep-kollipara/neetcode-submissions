class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_set = {};
        for (int num: nums){
            if (hash_set.find(num)==hash_set.end()){
                hash_set[num] = 1;
            }
            else{
                hash_set[num]++;
            }
        }
        vector<int> master_list ={};
        for (int n=0; n<k; n++){
            int max = -99999;
            int max_count = 0;
            for (int m=0; m < nums.size(); m++){
                if (hash_set[nums[m]] > max_count 
                and find(master_list.begin(), master_list.end(), nums[m])==master_list.end()){
                    max_count = hash_set[nums[m]];
                    max = nums[m];
                }
            }
            master_list.insert(master_list.end(), max);
        }
        return master_list;
    }
};
