class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        stk.push('s'); // default element for .top() to be usable
        for (char c: s){
            if (c=='[' or c=='{' or c=='(') stk.push(c);
            if (c==']' or c=='}' or c==')') {
                if ((c==']' and stk.top()=='[')
                or (c=='}' and stk.top()=='{')
                or (c==')' and stk.top()=='(')) stk.pop();
                else return false;
            }
        }
        if (stk.top()=='s') return true;
        /*if (stk.empty()) return true;*/
        else return false;
    }
};
