class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, h=matrix[0].size()*matrix.size()-1, m = l+(h-l)/2;
        while (l <= h) {
            int m_x = m%matrix[0].size();
            int m_y = m/matrix[0].size();
            if (matrix[m_y][m_x] < target) {
                l = m+1;
            } else if (matrix[m_y][m_x] > target) {
                h = m-1;
            } else return true;
            m = l + (h- l)/2;
        }
        cout << l << " " << m << " " << h << endl;
        return false;
    }
};
