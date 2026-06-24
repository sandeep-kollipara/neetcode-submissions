class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // using list of list of indices to represent queens - [[row, col], [row, col] ...]
        // design validator function
        auto validate_n_queens=[&](vector<pair<int,int>> positions) {
            // (can be skipped) make sure each row and column have one queen each, also 
            // add position to hashmap
            unordered_map<int, int> hashmap;
            for (auto& [a, b]: positions) hashmap[a]=b;
            for (auto& [a, b]: positions) {
                // increment x and y (x=y diagonal) and check if other queens exist
                int x=a, y=b;
                while (x<n-1) if (hashmap[++x]==++y) return false;
                // decrement x and y (x=y diagonal) and check if other queens exist
                x=a;
                y=b;
                while (x>0) if (hashmap[--x]==--y) return false;
                // increment x and decrement y (x+y=0 diagonal) and check if other queens exist
                x=a; 
                y=b;
                while (x<n-1) if (hashmap[++x]==--y) return false;
                // decrement x and increment y (x+y=0 diagonal) and check if other queens exist
                x=a; 
                y=b;
                while (x>0) if (hashmap[--x]==++y) return false;    
            }
            hashmap.clear();
            // else valid
            return true;
        };
        // use combinatorics to check all possible positions - assign one row to each queen, get permulations of columns
        // basically get all permulations of 0-(n-1)
        vector<int> nums(n, 0);
        for (int i=0; i<n; i++) nums[i]=i;
        vector<vector<int>> permute;
        auto backtrack=[](auto&& self, int i, vector<int> arr) {
            // base case or termination plus work
            if (i==arr.size()) return vector<vector<int>>(1,vector<int>());
            // traversal
            vector<vector<int>> perms = self(self, i+1, arr), perms2;
            for (auto v: perms) {
                for (int j=0; j<=v.size(); j++) {
                    vector<int> w(v);
                    w.insert(w.begin()+j, arr[i]);
                    perms2.push_back(w);
                }
            }
            return perms2;
        };
        permute = backtrack(backtrack, 0, nums);
        vector<vector<pair<int,int>>> solutions;
        for (auto a: permute) {
            //for (auto b: a) cout << b << " ";
            //cout << endl;
            vector<pair<int,int>> p;
            for (int j=0; j<a.size(); j++) p.push_back({j, a[j]});
            if (validate_n_queens(p)) solutions.push_back(p); 
        }
        //cout << solutions.size() << endl;
        // create the string format for output and return
        string empty = "";
        for (int i=0; i<n; i++) empty+='.';
        //cout << empty << endl;
        vector<vector<string>> output(solutions.size(), vector<string>(n,empty));
        for (int i=0; i<solutions.size(); i++) {
            for (auto& [a, b]: solutions[i]) output[i][a].replace(b,1,"Q");
        }
        //return {{""}};
        return output;
    }
};
