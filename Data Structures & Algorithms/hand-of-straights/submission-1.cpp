class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize!=0) return false;
        sort(hand.begin(), hand.end());
        int handSize = hand.size();
        //hand.erase(unique(hand.begin(),hand.end()),hand.end());
        unordered_map<int, int> hash_map;
        for (int i: hand) hash_map[i]++;
        int smallest_element = hand[0]/**min_element(hand.begin(), hand.end())*/;
        int i=0, j;
        while (i<handSize) {
            if (i%groupSize==0) { // initialize
                j=hand[0]/**min_element(hand.begin(), hand.end())*/;
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
            if (hash_map[j]==0) { // update (average time complexity O(1))
                hand.erase(remove(hand.begin(), hand.end(), j), hand.end());
            }
            j++;
            i++;
        }
        return true;
    }
};
