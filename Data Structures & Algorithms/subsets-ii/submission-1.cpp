class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // so duplicates line next to each other
        for(int k=0; k<nums.size(); k++) cout << nums[k] << " ";
        cout << endl;
        vector<int> init;
        function<vector<vector<int>>(vector<int>, int)> recurse_stagger_tree=[&](vector<int> base, int i) {
            if (i==nums.size()) return vector<vector<int>>({base}); // termination
            for(int k=0; k<base.size(); k++) cout << base[k] << " ";
            cout << endl;
            vector<vector<int>> target;
            int repetitions=1;
            for (int j=i; j<nums.size()-1; j++) {
                if (j+1<nums.size() and nums[j]==nums[j+1]) repetitions++;
                else break;
            }
            // without i
            vector<vector<int>> without_i, with_i;
            if (i<nums.size()) { 
                without_i = recurse_stagger_tree(base, i+repetitions);
                target.insert(target.end(),without_i.begin(),without_i.end());
            }
            // with multi i
            for (int k=0; k<repetitions; k++) {
                base.push_back(nums[i]);
                if (i<nums.size()) {
                    with_i = recurse_stagger_tree(base, i+repetitions);
                    target.insert(target.end(),with_i.begin(),with_i.end());
                }
            }
            return target;
        };
        return recurse_stagger_tree(init, 0);
    }
};
