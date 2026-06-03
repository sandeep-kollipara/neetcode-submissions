class Solution {
public:
    int calPoints(vector<string>& operations) {
        int j = 0;
        vector<int> record(operations.size(), 0);
        for (int i = 0; i < operations.size(); i++) {
            switch(operations[i][0]) {
                case '+':
                    record[j] = record[j-1] + record[j-2];
                    break;
                case 'C':
                    record[j-1] = 0;
                    j-=2;
                    break;
                case 'D':
                    record[j] = 2*record[j-1];
                    break;
                default:
                    record[j] = stoi(operations[i]);
            }
            j++;
        }
        return accumulate(record.begin(), record.end(), 0);
    }
};