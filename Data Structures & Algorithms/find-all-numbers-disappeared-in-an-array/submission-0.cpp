class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //int highest=INT_MIN;
        unordered_set<int> hashset;
        for (auto i: nums) {
            hashset.insert(i);
            //highest = max(i, highest);
        }
        int i=1;
        vector<int> missingno;
        while (i<=nums.size()){ //highest) {
            if (hashset.find(i)==hashset.end()) missingno.push_back(i); 
            i++;
        }
        return missingno;
    }
};