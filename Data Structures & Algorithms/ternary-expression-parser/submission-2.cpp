class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s;
        char a='\0', b='\0', c='\0';
        auto solve_stack=[&]() -> void { 
            if (a=='\0' and b=='\0' and c=='\0') {
                //c = (s.top()=='T') ? true : false;
                c = s.top();
                s.pop();
            } else if (a=='\0' and b=='\0') {
                a = s.top();
                s.pop();
            } else {
                b = s.top();
                s.pop();
                if (c=='T') s.push(a);
                else s.push(b);
                a = b = c ='\0';
            }
        };
        int j;
        bool solve=false;
        char d;
        //for (char d: expression) {
        //for (auto d=expression.rbegin(); d!=expression.rend(); ++d ) {
        for (int i=expression.size()-1; i>-1; i--) {
            d = expression[i];
            if (solve) {
                s.push(d);
                j=0;
                do{ 
                    solve_stack();
                    j++;
                } while(j<3);
                solve = false;
            } else if (d=='?') {
                solve = true;
            } else if (d==':') {
                solve = false;
            } else {
                s.push(d);
                solve = false;
            }
            //cout << s.top() << endl;
        }
        string str(1, s.top());
        return str;
    }
};
