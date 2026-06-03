class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<int>> hash_map = {};
        for (int i=0; i<nums.size(); i++){
            if (hash_map.find(nums[i])!=hash_map.end()){
                vector<int> idx = hash_map[nums[i]];
                idx.insert(idx.end(), i);
                hash_map[nums[i]] = idx;
            }
            else
            hash_map[nums[i]]={i};
        }
        vector<vector<int>> tray = {};
        vector<int> chosen_idx_list = {};
        for (int i=0; i<nums.size()-1; i++){
            /*bool break_flag = false;*/
            /*if (find(chosen_idx_list.begin(), chosen_idx_list.end(), i)!=chosen_idx_list.end()) continue;*/
            for (int j=i+1; j<nums.size(); j++){
                /*if (find(chosen_idx_list.begin(), chosen_idx_list.end(), j)!=chosen_idx_list.end()) continue;*/
                int target = nums[i] + nums[j];
                if (hash_map.find(-target)!=hash_map.end()){
                    for (int k: hash_map[-target]){ /*Copies not allowed*/
                        if (k > j 
                        /*and find(chosen_idx_list.begin(), chosen_idx_list.end(), k)==chosen_idx_list.end()*/){
                            vector<int> box = {nums[i], nums[j], -target};
                            tray.insert(tray.end(), box);
                            /*chosen_idx_list.insert(chosen_idx_list.end(), i);
                            chosen_idx_list.insert(chosen_idx_list.end(), j);
                            chosen_idx_list.insert(chosen_idx_list.end(), k);*/
                            /*break_flag = true;*/
                            /*break;*/ /* Only allows one k for given i and j */
                        }
                        /*break;*/ /* Misses the next iters */
                    }
                }
                /*if (break_flag==true) break;*/ /* Break the j cycle */
            }
        }
        if (tray.size()>1){
            vector<int> dropped_idx_list = {};
            for (int i=0; i<tray.size()-1; i++){
                for (int j=i+1; j<tray.size(); j++){
                    vector<int> vec1 = tray[i];
                    vector<int> vec2 = tray[j];
                    sort(vec1.begin(), vec1.end());
                    sort(vec2.begin(), vec2.end());
                    if (vec1 == vec2 
                    and find(dropped_idx_list.begin(), dropped_idx_list.end(), j)==dropped_idx_list.end()) dropped_idx_list.insert(dropped_idx_list.end(), j);
                }
            }
            sort(dropped_idx_list.begin(), dropped_idx_list.end(), greater<int>());
            for (int idx: dropped_idx_list) tray.erase(tray.begin() + idx);
        }
        return tray;
    }
};
