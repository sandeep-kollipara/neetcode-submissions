class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int remaining = students.size(), leftover = 0, temp;
        reverse(sandwiches.begin(), sandwiches.end());
        stack<int, vector<int>> s(sandwiches);
        queue<int> q;
        for (int i: students) {
            q.push(i);
        }
        while (leftover != remaining) {
            remaining = q.size();
            for (int i=0; i<remaining; i++) {
                if (s.empty()) break;
                if (s.top() == q.front()) {
                    s.pop();
                    q.pop();
                } else {
                    temp = q.front();
                    q.pop();
                    q.push(temp);
                }
            }
            leftover = q.size();
        }
        return q.size();
    }
};