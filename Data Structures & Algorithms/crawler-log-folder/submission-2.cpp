class Solution {
public:
    int minOperations(vector<string>& logs) {
        int distance=0;
        for (auto a: logs) {
            if (a=="./") { // no change
                continue;
            } else if (a=="../") { // parent
                distance--;
            } else { // subfolder
                distance++;
            }
            distance = max(distance, 0);
        }
        return max(distance,0);
    }
};