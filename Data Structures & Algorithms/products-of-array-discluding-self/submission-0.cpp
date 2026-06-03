class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>* nums_arr =  new vector<int>[1000];
        for (int i=0; i<nums.size(); i++){
            vector<int> vector1 = vector<int>(nums.begin(), nums.begin()+i);
            vector<int> vector2 = vector<int>(nums.begin()+i+1, nums.end());
            vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
            nums_arr[i] = vector1;
        }
        vector<int> product(nums.size(), 1);
        for (int i=0; i<nums.size(); i++){
            auto multi = accumulate(begin(nums_arr[i]), end(nums_arr[i]), 1, multiplies<int>());
            product[i] = multi;
        }
        return product;
    }
};
