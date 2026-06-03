class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        struct VectorHash { // https://stackoverflow.com/questions/29855908/c-unordered-set-of-vectors
            size_t operator()(const std::vector<int>& v) const {
                std::hash<int> hasher;
                size_t seed = 0;
                for (int i : v) {
                    seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
                }
                return seed;
            }
        };
        using MySet = std::unordered_set<std::vector<int>, VectorHash>;
        // assuming only positive integers in nums as negatives or zero can lead to infinite combinations
        int max_iterations = floor(target/(*min_element(nums.begin(), nums.end())));
        MySet combinations_hash_set = {};
        vector<vector<int>> self_cartesian_product;
        for (int num: nums) self_cartesian_product.push_back({});
        /*vector<vector<vector<int>>> all_cartesian_products = {self_cartesian_product};*/
        for (int i=0; i<max_iterations; i++) {
            vector<vector<int>> temp = {};
            for (int j=0; j<self_cartesian_product.size(); j++) {
                for (int k=0; k<nums.size(); k++) {
                    vector<int> ins = self_cartesian_product[j];
                    ins.push_back(nums[k]);
                    temp.push_back(ins);
                    sort(ins.begin(), ins.end());
                    /*for (int c: ins) cout << c << " ";
                    cout << endl;*/
                    if (accumulate(ins.begin(), ins.end(), 0)==target) combinations_hash_set.insert(ins);
                }
            }
            self_cartesian_product = temp;
            /*all_cartesian_products.push_back(self_cartesian_product);*/
        }
        // removing duplicates from solution array
        vector<vector<int>> result = {};
        /*for (vector<int> combination: combinations_hash_set){
            for (int c: combination) cout << c << " ";
            cout << endl;
        }*/
        for (vector<int> combination: combinations_hash_set) result.push_back(combination);
        return result;
    }
};
