class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int shake=0;
        for (auto v: shift) {
            if (v[0]==0) shake+=v[1];
            else shake-=v[1];
        }
        cout << shake << endl;
        if (shake>0) { // left
            shake = shake % s.length();
            return s.substr(shake, s.length()-shake) + s.substr(0, shake);
        } else { // right
            shake = abs(shake) % s.length();
            return s.substr(s.length()-shake, shake) + s.substr(0, s.length()-shake);
        }
    }
};
