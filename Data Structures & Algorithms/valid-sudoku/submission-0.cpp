class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> hash_set;
        // 9 horizontal
        for (vector<char> arr: board) {
            int counter = 0;
            for (char c: arr) if (c!='.') {
                hash_set.insert(c);
                counter++;
            }
            if (counter!=hash_set.size()) return false;
            hash_set.clear();
        }
        // 9 vertical
        for (int i=0; i<board[0].size(); i++) {
            int counter = 0;
            for (int j=0; j<board.size(); j++) if (board[j][i]!='.') {
                hash_set.insert(board[j][i]);
                counter++;
            }
            if (counter!=hash_set.size()) return false;
            hash_set.clear();
        }
        // 9 boxes
        vector<pair<int, int>> starting_points = {{0,0}, {0,3}, {0,6}, 
                                                  {3,0}, {3,3}, {3,6}, 
                                                  {6,0}, {6,3}, {6,6}};
        for (pair<int, int> coords: starting_points) {
            int counter = 0;
            for (int j=coords.first; j<coords.first+3; j++) {
                for (int i=coords.second; i<coords.second+3; i++) {
                    if (board[j][i]!='.') {
                        hash_set.insert(board[j][i]);
                        counter++;
                    }
                }
            }
            if (counter!=hash_set.size()) return false;
            hash_set.clear();
        }
        return true;
    }
};
