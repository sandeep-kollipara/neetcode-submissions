class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int a=0, b=0;
        for (int i=0; i<students.size(); i++) {
            if (students[i] == 1) a++;
            else b++; 
        }
        for (int i=0; i<sandwiches.size(); i++) {
            if ((a==0 and sandwiches[i]==1)
            or (b==0 and sandwiches[i]==0)) break;
            if (sandwiches[i] == 1) a--;
            else b--;
        }
        return a+b;
    }
};