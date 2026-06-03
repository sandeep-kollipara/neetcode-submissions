class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // filtering candidates for 1st element
        vector<vector<int>> candidates_for_one;
        int i=0;
        while (i<triplets.size()) {
            vector<int> trio = triplets[i];
            if (trio[0]==target[0] and trio[1]<=target[1] and trio[2]<=target[2]) {
                candidates_for_one.push_back(trio);
                //triplets.erase(triplets.begin()+i);
                //continue;
            }
            i++;
        }
        // filtering candidates for 2nd element
        vector<vector<int>> candidates_for_two;
        i=0;
        while (i<triplets.size()) {
            vector<int> trio = triplets[i];
            if (trio[0]<=target[0] and trio[1]==target[1] and trio[2]<=target[2]) {
                candidates_for_two.push_back(trio);
                //triplets.erase(triplets.begin()+i);
                //continue;
            }
            i++;
        }
        // filtering candidates for 3rd element
        vector<vector<int>> candidates_for_three;
        i=0;
        while (i<triplets.size()) {
            vector<int> trio = triplets[i];
            if (trio[0]<=target[0] and trio[1]<=target[1] and trio[2]==target[2]) {
                candidates_for_three.push_back(trio);
                //triplets.erase(triplets.begin()+i);
                //continue;
            }
            i++;
        }
        if (candidates_for_one.size()*candidates_for_two.size()*candidates_for_three.size()>0) {
            return true;
        }
        return false;
    }
};
