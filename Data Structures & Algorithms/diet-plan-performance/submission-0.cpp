class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        // initialize window
        int i=0, j=0, total=0, score=0;
        while (j<k) {
            total+=calories[j];
            j++;
        }
        if (total>upper) score++;
        else if (total<lower) score--;
        // sliding window
        while (j<calories.size()) {
            total+=calories[j];
            j++;
            total-=calories[i];
            i++;
            if (total>upper) score++;
            else if (total<lower) score--;
        }
        return score;
    }
};
