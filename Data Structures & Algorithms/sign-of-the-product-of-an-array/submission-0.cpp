class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negatives=0;
        for (int i: nums) {
            if (i==0) return 0;
            else if (i<0) negatives++; 
        }
        return 1-2*(negatives%2);
    }
};