class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int length = matrix[0].size(), breadth = matrix.size();
        function<pair<int, int>(int)> coords=[&](int overall) {
            return pair<int, int>({floor(overall/length),overall%length});
        };
        int low=0, high=length*breadth-1, mid;
        while (high-low>1){
            mid=ceil((low+high)/2);
            int x=coords(mid).first, y=coords(mid).second;
            cout << matrix[x][y] << endl;
            if (matrix[x][y] < target) low = mid;
            else if (matrix[x][y] > target) high = mid;
            else return true;
        }
        int x1=coords(low).first, y1=coords(low).second; // in case while loop doesn't run
        int x2=coords(high).first, y2=coords(high).second;
        if (matrix[x1][y1]==target or matrix[x2][y2]==target) return true;
        else return false;
    }
};
