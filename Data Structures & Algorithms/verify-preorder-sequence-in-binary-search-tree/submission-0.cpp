class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() < 3) return true;
        int root = preorder[0];
        int i=0;
        while (i<preorder.size()) {
            if (preorder[i] > root) break;
            i++;
        }
        vector<int> left(preorder.begin()+1, preorder.begin()+i);
        vector<int> right(preorder.begin()+i, preorder.end());
        // test
        if (right.size()>0 and *min_element(right.begin(), right.end())<root) return false;
        return verifyPreorder(left) and verifyPreorder(right);
    }
};
