class Solution {
public:
    int maxArea(vector<int>& heights) {
        unordered_map<int, vector<int>> inverted_heights = {};
        for (int i; i<heights.size(); i++){
            if (inverted_heights.find(heights[i])==inverted_heights.end()) 
            inverted_heights[heights[i]]={i};
            else{
                vector<int> temp = inverted_heights[heights[i]];
                temp.insert(temp.end(), i);
                inverted_heights[heights[i]]=temp;
            }
        }
        vector<int> sorted_heights = heights;
        unordered_map<int, int> area = {}; 
        sort(sorted_heights.begin(), sorted_heights.end(), greater<int>());
        int global_max_area = 0;
        for(int i=0; i< sorted_heights.size(); i++){
            int max_area = 0;
            if (i==0) area[sorted_heights[i]]=0;
            else{
                for (int j=0; j<i; j++){
                    int max_i = *max_element(inverted_heights[sorted_heights[i]].begin(), inverted_heights[sorted_heights[i]].end());
                    int max_j = *max_element(inverted_heights[sorted_heights[j]].begin(), inverted_heights[sorted_heights[j]].end());
                    int min_i = *min_element(inverted_heights[sorted_heights[i]].begin(), inverted_heights[sorted_heights[i]].end());
                    int min_j = *min_element(inverted_heights[sorted_heights[j]].begin(), inverted_heights[sorted_heights[j]].end());
                    int width = max({max_i - min_j, max_j - min_i});
                    int local_area = width*sorted_heights[i];
                    cout << local_area << " ";
                    if (max_area < local_area) max_area = local_area;
                }
                area[sorted_heights[i]]=max_area;
            }
            if (global_max_area < max_area) global_max_area = max_area;
            cout << max_area << endl;
        }
        return global_max_area;
    }
};
