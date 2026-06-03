class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> opers = {"+","-","*","/"};
        stack<string> calci_stack;
        int left, right;
        while (tokens.size()!=0) {
            string curr = tokens[0];
            calci_stack.push(tokens[0]);
            tokens.erase(tokens.begin());
            if (find(opers.begin(),opers.end(),curr)!=opers.end()) {
                calci_stack.pop();
                right = stoi(calci_stack.top()); // reverse
                calci_stack.pop();
                left = stoi(calci_stack.top()); // reverse
                calci_stack.pop();
                if (curr=="+") left+=right;
                else if (curr=="-") left-=right;
                else if (curr=="*") left*=right;
                else if (curr=="/") left/=right;
                else ; // shouldn't happen
                calci_stack.push(to_string(left));
                cout << left << endl;
            }
        }
        return stoi(calci_stack.top());
    }
};
