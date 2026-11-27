class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        cout<< pow(2,ceil(log2(left)));
        if (pow(2,floor(log2(left)+1)) < right) return 0;
        int j=-1;
        for (int i=left; i<=right; i++) j&=i;
        return j;
    }
};