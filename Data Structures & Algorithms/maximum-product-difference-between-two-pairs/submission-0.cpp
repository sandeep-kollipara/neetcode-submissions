class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int w=-1, x=-1, y=-1, z=-1, maximum=INT_MIN, minimum=INT_MAX; // z < y < x < w
        for (auto& i: nums) {
            if (maximum < i) {
                w = i;
                x = maximum;
                maximum = i;
            } else x = max(x, i);
            if (minimum > i) {
                z = i;
                y = minimum;
                minimum = i;
            } else y = min(y, i);
        }
        //cout << w << " " << x << " " << y << " " << z;
        return w*x - y*z;
    }
};