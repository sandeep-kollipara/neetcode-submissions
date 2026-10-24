class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        while (s.length()) {
            char c = s.back();
            s.pop_back();
            if (stk.size() 
            and stk.top()==')' 
            and c=='(') stk.pop();
            else stk.push(c);
        }
        return stk.size();
    }
};
