class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> s;
        while(!operations.empty()) {
            s.push(operations[0]);
            operations.erase(operations.begin());
            if (s.top()=="+") {
                s.pop();
                string a = s.top();
                s.pop();
                string b = s.top();
                s.pop();
                s.push(b);
                s.push(a);
                s.push(to_string(stoi(a)+stoi(b)));
            }
            else if (s.top()=="D") {
                s.pop();
                string a = s.top();
                s.pop();
                s.push(a);
                s.push(to_string(2*stoi(a)));
            }
            else if (s.top()=="C") {
                s.pop();
                s.pop();
            }
            else ; // pass
        }
        int sum=0;
        while (!s.empty()) {
            cout << s.top() << endl;
            sum+=stoi(s.top());
            s.pop();
        }
        return sum;
    }
};