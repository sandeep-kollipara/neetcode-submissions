class Solution {
public:
    string reverseParentheses(string s) {
        auto stack_shift=[](string r){
            stack<char> main, side;
            int count=0;
            bool shift=false;
            while (r.length()) {
                char c = r.back();
                r.pop_back();
                if (c==')') count++;
                else if (c=='(') count--;
                if (c==')' and count==1) { // start loading side
                    shift = true;
                } else if (c=='(' and count==0) { // end side phase and unload into main
                    shift = false;
                    while (not side.empty()) {
                        main.push(side.top());
                        side.pop();
                    }
                } else {
                    if (shift) {
                        side.push(c);
                    } else {
                        main.push(c);
                    }
                }
            }
            while (not main.empty()) {
                char c=main.top();
                if (c==')') c='(';
                else if (c=='(') c=')';
                r+=c;
                main.pop();
            }
            return r;
        };
        int depth=0;
        // calculating depth for stack shifts
        for (char c: s) if (c=='(') depth++;
        // running the stack_shift lambda for all parenthesis
        for (int i=0; i<depth; i++) s = stack_shift(s);
        return s;
    }
};
