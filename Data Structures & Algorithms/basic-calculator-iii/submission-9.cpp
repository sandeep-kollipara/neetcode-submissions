class Solution {
public:
    int calculate(string s) {
        //if (s[0]=='-') s = '0' + s;
        // detect parenthesis and resolve them first
        stack<int> stk;
        int start;
        string sub, recurse;
        for (int i=0; i<s.length(); i++) {
            if (s[i]=='(') stk.push(i);
            else if (s[i]==')') {
                if (stk.size()==1) {
                    start = stk.top();
                    sub = s.substr(start+1,i-start-1);
                    recurse = to_string(calculate(sub));
                    //if (recurse[0]=='-') recurse = '0' + recurse;
                    //cout << recurse << "," << start << endl;
                    int j;
                    for (j=0; j<recurse.length(); j++) s[start+j] = recurse[j];
                    for (int k=start+j; k<=i; k++) s[k] = '!'; 
                }
                stk.pop();
            }
        }
        for (int i=s.length()-1; i>-1; i--) {
            if (s[i]=='!') s.erase(s.begin()+i);
        }
        int k=0;
        while (true) {
            if (k==s.length()) break; 
            if (s[k]=='-' and s[k+1]=='-') {
                s[k] = '+';
                s.erase(s.begin()+k+1);
            } else if (s[k]=='+' and s[k+1]=='-') {
                s.erase(s.begin()+k);
            }
            k++;
        }
        cout << s << endl;
        // solve the string for just the operations
        vector<char> operators;
        vector<int> operands;
        string num;
        for (int i=0; i<s.length(); i++) {
            switch(s[i]) {
                case '-':
                    if (num!="") {
                        operands.push_back(stoi(num));
                        operators.push_back('+');
                    }
                    num = "-";
                    break;
                    //if (i==0) {
                    //    num+=s[i];
                    //    break;
                    //}
                case '+':
                case '*':
                case '/':
                    //cout << "num" << num << endl;
                    if (num!="") operands.push_back(stoi(num));
                    num = "";
                    operators.push_back(s[i]);
                    break;
                default:
                    num+=s[i];
            }
        }
        if (num!="") operands.push_back(stoi(num));
        // division & multiplication
        //for (int i=operators.size()-1; i>-1; i--) {
        int i=0;
        while(i<operators.size()) {
            if (operators[i]=='/') {
                operators.erase(operators.begin()+i);
                operands[i] = operands[i]/operands[i+1];
                cout << "/" << operands[i] << endl;
                operands.erase(operands.begin()+i+1);
            } else if (operators[i]=='*') {
                operators.erase(operators.begin()+i);
                operands[i] = operands[i]*operands[i+1];
                cout << "*" << operands[i] << endl;
                operands.erase(operands.begin()+i+1);
            } else i++;
        }
        i=0;
        //for (int i=operators.size()-1; i>-1; i--) {
        while(operators.size()!=0) {
            if (operators[i]=='+') {
                operators.erase(operators.begin()+i);
                operands[i] = operands[i]+operands[i+1];
                cout << "+" << operands[i] << endl;
                operands.erase(operands.begin()+i+1);
            } else if (operators[i]=='-') {
                operators.erase(operators.begin()+i);
                operands[i] = operands[i]-operands[i+1];
                cout << "-" << operands[i] << endl;
                operands.erase(operands.begin()+i+1);
            }
        }
        return operands[0];
    }
};
