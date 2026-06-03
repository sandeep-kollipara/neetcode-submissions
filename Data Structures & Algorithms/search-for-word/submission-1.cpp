class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char,vector<pair<int,int>>> hash_map = {};
        for (int j=0; j<board.size(); j++) {
            for (int i=0; i<board[0].size(); i++) {
                pair<int, int> loc = {i, j};
                if (hash_map.find(board[j][i])==hash_map.end()) hash_map[board[j][i]] = {loc};
                else {
                    vector<pair<int, int>> temp = hash_map[board[j][i]];
                    temp.push_back(loc);
                    hash_map[board[j][i]] = temp;
                }
            }
        }
        int i_max = board[0].size()-1, j_max = board.size()-1;
        //cout << i_max << " " << j_max << endl;
        if ((i_max+1)*(j_max+1) < word.length()) return false;
        vector<vector<pair<int,int>>> paths = {};
        int k = 0;
        while (k < word.length()) {
            if (hash_map.find(word[k])==hash_map.end()) return false;
            if (k==0) for (pair<int,int> loc: hash_map[word[k]]) paths.push_back({loc});
            else{
                int paths_size = paths.size();
                for(int l=0; l<paths_size; l++) {
                    vector<pair<int,int>> path = paths[l];
                    pair<int,int> last_loc = path[path.size()-1];
                    int i = last_loc.first, j = last_loc.second;
                    cout << i << " " << j << endl;
                    // up
                    if (j>0) {
                        if (board[j-1][i]==word[k]) {
                            vector<pair<int,int>> temp = path;
                            temp.push_back({i, j-1});
                            paths.push_back(temp);
                        }
                    }
                    // bottom
                    if (j<j_max) {
                        if (board[j+1][i]==word[k]) {
                            vector<pair<int,int>> temp = path;
                            temp.push_back({i, j+1});
                            paths.push_back(temp);
                        }
                    }
                    // left
                    if (i>0) {
                        if (board[j][i-1]==word[k]) {
                            vector<pair<int,int>> temp = path;
                            temp.push_back({i-1, j});
                            paths.push_back(temp);
                        }
                    }
                    // right
                    if (i<i_max) {
                        if (board[j][i+1]==word[k]) {
                            vector<pair<int,int>> temp = path;
                            temp.push_back({i+1, j});
                            paths.push_back(temp);
                        }
                    }
                }
                if (paths.size()>paths_size) paths = vector<vector<pair<int,int>>>(paths.begin()+paths_size, paths.end());
                else paths = {};
            }
            k++;
        }
        cout << paths.size() << endl;
        for (vector<pair<int,int>>path: paths) {
            set<pair<int,int>> points = {};
            for (pair<int,int>coords: path) {
                points.insert(coords);
                cout << "(" << coords.second << "," << coords.first << ")" << "";
            }
            cout << endl;
            if (path.size()!=word.length()) continue;
            if (points.size()==word.length()) return true;
        }
        return false;
    }
};
