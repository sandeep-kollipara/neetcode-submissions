class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        function<int(vector<int>)> xor_total=[](vector<int> combo) {
            if (combo.size()==0) return 0;
            int subtotal = combo[0];
            for (int i=1; i<combo.size(); i++) {
                subtotal = subtotal ^ combo[i];
            }
            return subtotal;
        };
        vector<vector<int>> /*combinations,*/ temp={{}}, temp2;
        int i=0;
        while (i<nums.size()) {
            temp2 = {};
            for (vector<int> combo: temp) {
                temp2.push_back(combo);
                combo.insert(combo.end(), nums[i]);
                temp2.push_back(combo);
            }
            temp = temp2;
            //combinations.insert(combinations.end(), temp.begin(), temp.end());
            i++;
        }
        int sum=0;
        for (vector<int> combo: temp/*combinations*/) {
            //for (int i: combo) cout << i << " ";
            //cout << endl;
            sum+=(xor_total(combo));
        }
        return sum;
    }
};