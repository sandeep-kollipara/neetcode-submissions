class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> out;
        bool carry = true;
        for (int i=digits.size()-1; i>-1; i--) {
            int add = digits[i];
            if (carry) {
                add++;
                carry=false;
            }
            if (add==10) {
                out.insert(out.begin(), 0);
                carry = true;
            }
            else out.insert(out.begin(), add);
        }
        if (carry) out.insert(out.begin(), 1);
        return out;
    }
};
