class Solution {
public:
    int trap(vector<int>& height) {
        int i=0, j=0, left_peak, rain_height;//, rain_water=0;
        vector<int> rain_water(height.size(), 0);
        vector<int> right_peak(height.size(), 0);
        right_peak[right_peak.size()-1] = 0;//height[height.size()-1];
        bool first_peak=false;
        for (int i=right_peak.size()-2; i>-1; i--) {
            if (i > -1 and height[i]<height[i+1]) first_peak = true;
            if (first_peak) right_peak[i] = max(right_peak[i+1], height[i+1]);//height[i]);
        }
        for (int a: right_peak) cout << a << " ";
        cout << endl;
        while(i < height.size()) {
            //initialize the i and j at a peak (far edge)
            while (i+1<height.size() and height[i+1] >= height[i]) {
                i++;
            }
            left_peak = height[i];
            j=i;
            //traverse until the next peak (can be higher or lower)
            while (j+1 < height.size() 
            and height[j+1] < left_peak
            and height[j+1] < right_peak[i]) {
                j++;
            }
            // calculate rainwater inbetween
            rain_height = min(left_peak, right_peak[i]);
            while (i<=j) {
                //rain_water+=(rain_height - height[i]);
                if (rain_height > height[i]) rain_water[i] = rain_height - height[i];
                i++;
            }
            // reset for next iteration
            //i++;
            //j++;
        }
        //return rain_water;
        for (int i: rain_water) cout << i << " ";
        cout << endl;
        return accumulate(rain_water.begin(), rain_water.end(), 0);
    }
};
