class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize!=0) return false;
        //sort(hand.begin(), hand.end());
        unordered_map<int, int> hash_map;
        for (int i: hand) hash_map[i]++;
        int smallest_element = *min_element(hand.begin(), hand.end());
        int i=0, j, handSize = hand.size();
        while (i<handSize) {
            if (i%groupSize==0) { // initialize
                j=*min_element(hand.begin(), hand.end());
                cout<< "smallest element: " << j << endl;
                if (hash_map.find(j)==hash_map.end()) return false;
                hash_map[j]--;
            }
            else { // remaining
                if (hash_map.find(j)==hash_map.end()) return false;
                cout << "next element: " << j << endl;
                if (hash_map[j]>0)hash_map[j]--;
                else return false;
            }
            if (hash_map[j]==0) { // update
                hand.erase(remove(hand.begin(), hand.end(), j), hand.end());
            }
            j++;
            i++;
        }
        return true;
    }
};
