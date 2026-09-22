class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> mergedList;
        int i=0, j=0, imax=firstList.size(), jmax=secondList.size();
        while (i<imax or j<jmax) {
            // if either has reached limit, add the remaining to the list
            if (j==jmax or i==imax) {
                break;
            }
            // check if there is intersection, if yes merge and save
            else if (firstList[i][0] <= secondList[j][0] 
            and firstList[i][1] >= secondList[j][0]
            and firstList[i][1] <= secondList[j][1]) {
                cout << "insert1 " << secondList[j][0] << "," << firstList[i][1] << endl;
                mergedList.push_back({secondList[j][0],firstList[i][1]});
                i++;
            } else if (firstList[i][0] <= secondList[j][0] 
            and firstList[i][1] >= secondList[j][1]) {
                cout << "insert2 " << secondList[j][0] << "," << secondList[j][1] << endl;
                mergedList.push_back({secondList[j][0],secondList[j][1]});
                j++;
            } else if (secondList[j][0] <= firstList[i][0]
            and secondList[j][1] >= firstList[i][0]
            and firstList[i][1] >= secondList[j][1]) {
                cout << "insert3 " << firstList[i][0] << "," << secondList[j][1] << endl;
                mergedList.push_back({firstList[i][0],secondList[j][1]});
                j++;
            } else if (secondList[j][0] <= firstList[i][0]
            and secondList[j][1] >= firstList[i][1]) {
                cout << "insert4 " << firstList[i][0] << "," << firstList[i][1] << endl;
                mergedList.push_back({firstList[i][0],firstList[i][1]});
                i++;
            }
            // else add the earlier one to the list and keep the latest one
            else {
                cout << "skip" << endl;
                if (firstList[i][1] > secondList[j][1]) {
                    j++;
                } else {
                    i++;
                }
            }
        }
        return mergedList;
    }
};