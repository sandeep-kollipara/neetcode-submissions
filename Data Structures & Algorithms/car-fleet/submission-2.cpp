class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int> hash_map;
        for (int i=0; i<position.size(); i++) hash_map[position[i]] = speed[i]; // positions are unique
        sort(position.begin(), position.end(), greater<int>());
        float min_time = (target - position[0])/hash_map[position[0]];
        int fleet_count=1;
        for (int i=1; i<position.size(); i++) {
            float new_time = (target-position[i])/(float)hash_map[position[i]];
            cout << new_time << endl;
            // check if each position reaches target within min_time:
            // (if yes) merge to prev fleet (else no) create new fleet and recalculate the min_time and continue
            if (new_time <= min_time) continue;
            else {
                fleet_count++;
                min_time = new_time;
            }
        }
        return fleet_count;
    }
};
