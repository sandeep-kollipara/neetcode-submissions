class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashmap;
        stack<int> stk;
        stk.push(-1);
        for (int i=nums2.size()-1; i>-1; i--) {
            // Two operations: if top > curr, do nothing and save. 
            // Else top <= curr, pop until its higher and save
            if (stk.top() > nums2[i]) {
                ;
            } else {
                while (stk.size()>1 and stk.top()<=nums2[i]) stk.pop();
            }
            // Update hashmap
            hashmap[nums2[i]] = stk.top();
            // add the curr to stack
            stk.push(nums2[i]);
        }
        vector<int> res;
        for (auto i: nums1) res.push_back(hashmap[i]);
        return res;
    }
};