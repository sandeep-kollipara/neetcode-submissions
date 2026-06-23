class Solution {
public:
    int candy(vector<int>& ratings) {
        // start off the first child with zero and track the flow of ratings
        vector<int> flow_left(ratings.size(), 1), flow_right(ratings.size(), 1), flow(ratings.size(), 1);
        int candies=1;
        for (int i=1; i<ratings.size(); i++) {
            // reset
            if (i+1<ratings.size() and ratings[i-1]>=ratings[i] and ratings[i+1]>ratings[i]) candies = 1;
            // uphill increase
            if (ratings[i]>ratings[i-1]) flow_left[i]=(++candies);
            else {
                flow_left[i] = 1;
                candies = 1;
            }
        }
        candies=1;
        for (int i=ratings.size()-2; i>-1; i--) {
            // reset
            if (i>0 and ratings[i-1]>ratings[i] and ratings[i+1]>=ratings[i]) candies=1;
            // uphill increase (reverse)
            if (ratings[i]>ratings[i+1]) flow_right[i]=(++candies);
            else {
                flow_right[i] = 1;
                candies = 1;
            }
        }
        for (int i=0; i<ratings.size(); i++) {
            flow[i] = max(flow_left[i], flow_right[i]);
            //cout << flow[i] << " ";
        }
        return accumulate(flow.begin(), flow.end(), 0);
    }
};