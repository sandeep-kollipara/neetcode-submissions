class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        // matrix layer peel
        int width=matrix[0].size(), height=matrix.size();
        while (width>1 and height>1) {
            // peel outer layer
            spiral.insert(spiral.end(), matrix[0].begin(), matrix[0].end());
            for (int i=1; i<height-1; i++) spiral.push_back(matrix[i][width-1]);
            spiral.insert(spiral.end(), matrix[height-1].rbegin(), matrix[height-1].rend());
            for (int i=height-2; i>0; i--) spiral.push_back(matrix[i][0]);
            // update matrix as the remaining part
            matrix.erase(matrix.begin());
            matrix.erase(--matrix.end());
            for (int i=0; i<matrix.size(); i++) {
                matrix[i].erase(matrix[i].begin());
                matrix[i].erase(--matrix[i].end());
            }
            width-=2;
            height-=2;
        }
        for(vector<int> m: matrix) for(int i: m)  cout << i << " ";
        cout << endl;
        if (matrix.size()>0) {
            if (matrix.size()==1) spiral.insert(spiral.end(), matrix[0].begin(), matrix[0].end());
            else for (vector<int> m: matrix) spiral.insert(spiral.end(), m.begin(), m.end());
        }
        return spiral;
    }
};
