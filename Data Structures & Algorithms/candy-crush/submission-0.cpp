class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        vector<vector<int>> blueprint(board.size(), vector<int>(board[0].size(), 0));
        bool change = true;
        while (change){
            change = false;
            bool two, three;
            // detect all positions
            for (int i=0; i<board.size(); i++) {
                two = three = false;
                for (int j=0; j<board[0].size(); j++) {
                    // horizontal search
                    if (j>0 and board[i][j]==board[i][j-1]) {
                        if (three) {
                            blueprint[i][j] = -1;
                        } else if (two) {
                            three=true;
                            blueprint[i][j] = blueprint[i][j-1] = blueprint[i][j-2] = -1;
                        } else {
                            two=true;
                        }
                    } else {
                        two = three = false;
                    }
                }
            }
            for (int j=0; j<board[0].size(); j++) {
                two = three = false;
                for (int i=0; i<board.size(); i++) {
                    // vertical search
                    if (i>0 and board[i][j]==board[i-1][j]) {
                        if (three) {
                            blueprint[i][j] = -1;
                        } else if (two) {
                            three=true;
                            blueprint[i][j] = blueprint[i-1][j] = blueprint[i-2][j] = -1;
                        } else {
                            two=true;
                        }
                    } else {
                        two = three = false;
                    }
                }
            }
            // crush the positions by columns, gravity falls
            int k;
            for (int j=0; j<board[0].size(); j++) {
                k = board.size() - 1;
                for (int i=board.size()-1; i>=0; i--) {
                    // vertical sweep
                    if (blueprint[i][j]==-1 and i==k) blueprint[i][j] = 0;
                    else if (blueprint[i][j]==-1 and i!=k) blueprint[i][j] = 0;
                    else if (blueprint[i][j]!=-1 and i==k) k--;
                    else {
                        board[k][j] = board[i][j];
                        board[i][j] = -1;
                        k--;
                        change = true;
                    }
                }
                for (int i=k; i>=0; i--) {
                    // remaining
                    board[i][j] = 0;
                }
            }
        }
        return board;
    }
};
