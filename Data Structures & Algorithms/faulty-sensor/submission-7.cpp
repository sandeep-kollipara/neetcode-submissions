class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        int i=0, j=0;
        while (i<sensor1.size()-1 and j<sensor2.size()-1){
            if (sensor1[i]==sensor2[j]) {
                i++;
                j++;
            } else {
                if (i<sensor1.size()-1 and sensor1[i+1]==sensor2[i]) {
                    i++;
                }
                if (j<sensor2.size()-1 and sensor1[j]==sensor2[j+1]) {
                    j++;
                }
            }
        }
        //cout << "i" << i << endl;
        //cout << "j" << j;
        if (i==j) return -1;
        else if (i<j) return 1;
        else return 2;
    }
};
