class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize!=0) return false;
        sort(hand.begin(), hand.end());
        int handSize = hand.size();
        vector<stack<int>> stacks(hand.size()/groupSize);
        while (!hand.empty()) {
            int next = hand[0];
            hand.erase(hand.begin());
            for (int i=0; i<stacks.size(); i++) {
                if (stacks[i].size()==groupSize) { // stack is full
                    ; // pass
                }
                else if (stacks[i].size()!=0 and stacks[i].top()!=next-1) { // stack is not full and not empty
                    ; // pass
                }
                else if (stacks[i].size()!=0 and stacks[i].top()==next-1) { // stack is not full and not empty
                    stacks[i].push(next);
                    break;
                }
                else if (stacks[i].size()==0) { // stack is empty
                    stacks[i].push(next);
                    break;
                }
                if (i==stacks.size()-1) return false;
            }
        }
        return true;
    }
};
