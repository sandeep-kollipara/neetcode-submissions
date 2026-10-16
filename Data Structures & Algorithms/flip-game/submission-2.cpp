class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState){
        vector<string> possibilities;
        for (auto i=1; i<currentState.length(); ++i) {
            if (currentState[i]==currentState[i-1] and currentState[i]=='+') {
                string temp = currentState;
                if (temp[i]=='+') temp[i] = temp[i-1] = '-';
                //else temp[i] = temp[i-1] = '+';
                possibilities.push_back(temp);
            }
        }
        return possibilities;
    }
};
