class Excel {
    vector<vector<int>> sheet;
    unordered_map<string, vector<string>> hashmap;
    int length, breadth;
public:
    Excel(int height, char width) {
        length = height;
        breadth = (int) (width - 'A') + 1;
        sheet = vector<vector<int>>(height, vector<int>(breadth, 0));
    }
    
    void set(int row, char column, int val) {
        if (hashmap.find(string(1, column)+to_string(row))!=hashmap.end()) hashmap.erase(string(1, column)+to_string(row));
        sheet[row-1][(int)(column-'A')] = val;
    }
    
    int get(int row, char column) {
        if (hashmap.find(string(1, column)+to_string(row))!=hashmap.end()) {
            cout << "Sum found: " << row << "," << column << endl;
            return sum(row, column, hashmap[string(1, column)+to_string(row)]);
        }
        cout << "Val found: " << row << "," << column << endl;
        return sheet[row-1][(int)(column-'A')];
    }
    
    int sum(int row, char column, vector<string> numbers) {
        hashmap[string(1, column)+to_string(row)] = numbers;
        cout << "Sum registered: " << row << "," << column << endl;
        auto check_range=[](string s) {
            int colon=INT_MAX;
            for (int i=0; i<s.length(); i++) {
                if (s[i]==':') colon=i;
            }
            if (colon!=INT_MAX) return colon;
            return -1;
        };
        auto get_range_sum=[&](string start, string end) {
            int sum=0;
            for (int i=(int)start[0]; i<=(int)end[0]; i++) {
                for (int j=stoi(start.substr(1,start.length()-1)); j<=stoi(end.substr(1,end.length()-1)); j++) {
                    sum+=get(j, (char)i);
                }
            }
            return sum;
        };
        int total=0;
        for (string s: numbers) {
            int div = check_range(s);
            if (div!=-1) {
                string begin=s.substr(0,div), last=s.substr(div+1,s.length()-div-1);
                total+=get_range_sum(begin, last);
            } else {
                total+=get_range_sum(s, s);
            }
        }
        //set(row, column, total);
        return total;
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */
