class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> hashset;
        hashset.insert("0_0");
        int lat=0, lon=0;
        for (char c: path) {
            if (c=='N') lat++;
            else if (c=='E') lon++;
            else if (c=='W') lon--;
            else lat--;
            string loc = to_string(lat) + '_' + to_string(lon);
            if (hashset.find(loc)!=hashset.end()) return true;
            else hashset.insert(loc);
        }
        return false;
    }
};